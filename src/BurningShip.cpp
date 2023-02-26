#include "BurningShip.h"
#include <cmath>

BurningShip::BurningShip( ) 
: ComplexFractal() {
}

BurningShip::BurningShip( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ) 
: ComplexFractal(height, width, min_x, max_x, min_y, max_y) {
}

BurningShip::~BurningShip( ) {
}

void BurningShip::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const {
    x1 = x0*x0 - y0*y0 + a;
    y1 = -2*std::abs(x0*y0) + b;
}

int BurningShip::calculatePlaneEscapeCount( const double& a, const double& b ) const {
	int escapeCount = 0;
    double x = a;
    double y = b;
    double x2;
    double y2;
    double distanceFromOrigin;

	distanceFromOrigin = std::sqrt((x * x) + (y * y));
	
	while (distanceFromOrigin <= 2 && escapeCount < getMaxNumber()) {
		calculateNextPoint(x, y, a, b, x2, y2);

		x = x2;
		y = y2;

		distanceFromOrigin = std::sqrt((x * x) + (y * y));
        escapeCount++;
	}

	return escapeCount;
}

int BurningShip::calculateNumber( const int& row, const int& column ) const {
	double x;
    double y;

	if (row < 0 || row >= getHeight() || column < 0 || column >= getWidth()) {
		return -1;
	}

	x = calculatePlaneXFromPixelColumn(column);
	y = calculatePlaneYFromPixelRow(row);

	return calculatePlaneEscapeCount(x, y);
}