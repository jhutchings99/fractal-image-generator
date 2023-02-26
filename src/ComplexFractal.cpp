#include "ComplexFractal.h"
#include <cmath>

ComplexFractal::ComplexFractal( )
: ThreadedGrid(200, 300), mMinX(-1.5), mMaxX(1.5), mMinY(-1.0), mMaxY(1.0), mDeltaX(0.01), mDeltaY(0.01) {
}

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
: ThreadedGrid(height, width), mMinX(min_x), mMaxX(max_x), mMinY(min_y), mMaxY(max_y), mDeltaX(0.01), mDeltaY(0.01) {
}

ComplexFractal::~ComplexFractal( ) {
}

double ComplexFractal::getMinX( ) const {
    return mMinX;
}

double ComplexFractal::getMaxX( ) const {
    return mMaxX;
}

double ComplexFractal::getMinY( ) const {
    return mMinY;
}

double ComplexFractal::getMaxY( ) const {
    return mMaxY;
}

void ComplexFractal::setGridSize( const int& height, const int& width ) {
    if (height >= 2 && width >= 2) {
        NumberGrid::setGridSize(height, width);
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}

void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ) {
    if (min_x != max_x && min_y != max_y && min_x >= -2.0 && min_x <= 2.0 && max_x >= -2.0 && max_x <= 2.0 && min_y >= -2.0 && min_y <= 2.0 && max_y >= -2.0 && max_y <= 2.0) {
        if (min_x > max_x) {
            mMinX = max_x;
            mMaxX = min_x;
        } else {
            mMinX = min_x;
            mMaxX = max_x;
        }

        if (min_y > max_y) {
            mMinY = max_y;
            mMaxY = min_y;
        } else {
            mMinY = min_y;
            mMaxY = max_y;
        }

        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}

double ComplexFractal::getDeltaX( ) const {
    return mDeltaX;
}

double ComplexFractal::getDeltaY( ) const {
    return mDeltaY;
}

void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ) {
    if (delta_x > 0 && delta_y > 0) {
        mDeltaX = delta_x;
        mDeltaY = delta_y;
    }
}

double ComplexFractal::calculateDeltaY( ) const {
    return (mMaxY - mMinY) / (getHeight() - 1);
}

double ComplexFractal::calculateDeltaX( ) const {;
    return (mMaxX - mMinX) / (getWidth() - 1);

}

double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const {
    if (column < 0 || column >= getWidth()) {
        return 0;
    }

    return mMinX + column * mDeltaX;
}

double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const {
    if (row < 0 || row >= getHeight()) {
        return 0;
    }

    return mMaxY - row * mDeltaY;
}

void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const {
    if (calculatePlaneXFromPixelColumn(column) == 0 || calculatePlaneYFromPixelRow(row) == 0) {
        x = 0;
        y = 0;
    } else {
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
}

int ComplexFractal::calculateNumber( const int& row, const int& column ) const {
    if (row < 0 || row >= getHeight() || column < 0 || column >= getWidth()) {
        return -1;
    }

    double x = 0;
    double y = 0;
    calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
    int value = std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y));
    return value;
}

void ComplexFractal::zoomPlane(const double& zoom_factor) {
    double currentX = mMaxX - mMinX;
    double currentY = mMaxY - mMinY;

    double desiredX = currentX * zoom_factor;
    double desiredY = currentY * zoom_factor;

    double xChange = (currentX - desiredX) / 2;
    double yChange = (currentY - desiredY) / 2;

    double newMinX = mMinX + xChange;
    if (newMinX < -2.0) {
        newMinX = -2.0;
    }

    double newMaxX = mMaxX - xChange;
    if (newMaxX > 2.0) {
        newMaxX = 2.0;
    }

    double newMinY = mMinY + yChange;
    if (newMinY < -2.0) {
        newMinY = -2.0;
    }

    double newMaxY = mMaxY - yChange;
    if (newMaxY > 2.0) {
        newMaxY = 2.0;
    }

    setPlaneSize(newMinX, newMaxX, newMinY, newMaxY);
}