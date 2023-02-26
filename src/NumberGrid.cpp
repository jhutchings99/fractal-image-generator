#include <iostream>
#include "NumberGrid.h"
#include "PPM.h"
#include "ColorTable.h"

NumberGrid::NumberGrid() 
: mHeight(300), mWidth(400), mMaxValue(255), mGridNumbers(mHeight * mWidth, 0) {
}

NumberGrid::NumberGrid( const int& height, const int& width ) 
: mHeight(height), mWidth(width), mMaxValue(255), mGridNumbers(mHeight * mWidth, 0) {
}

NumberGrid::~NumberGrid() {
}

int NumberGrid::getHeight() const {
    return mHeight;
}

int NumberGrid::getWidth() const {
    return mWidth;
}

int NumberGrid::getMaxNumber() const {
    return mMaxValue;
}

void NumberGrid::setGridSize( const int& height, const int& width ) {
    if (height >= 2 && width >= 2) {
        mHeight = height;
        mWidth = width;

        mGridNumbers.resize(height * width);
    }
}

void NumberGrid::setMaxNumber( const int& number ){
    if (number >= 0) {
        mMaxValue = number;
    }
}

const std::vector< int >& NumberGrid::getNumbers( ) const {
    return mGridNumbers;
}

int NumberGrid::index( const int& row, const int& column ) const {
    int index = row * mWidth + column;
    return index;
}

bool NumberGrid::indexValid( const int& row, const int& column ) const {
    if (row >= mHeight) {
        return false;
    }

    if (row < 0) {
        return false;
    }

    if (column >= mWidth) {
        return false;
    }

    if (column < 0) {
        return false;
    }

    return true;
}

bool NumberGrid::numberValid( const int& number ) const {
    if (number < 0) {
        return false;
    }

    if (number > mMaxValue) {
        return false;
    }

    return true;
}

int NumberGrid::getNumber( const int& row, const int& column ) const {
    if (indexValid(row, column)) {
        int number = mGridNumbers[index(row, column)];
        return number;
    } else {
        return -1;
    }
}

void NumberGrid::setNumber( const int& row, const int& column, const int& number ) {
    if (indexValid(row, column) && numberValid(number)) {
        mGridNumbers[index(row, column)] = number;
    }
}

void NumberGrid::setPPM( PPM& ppm ) const {
    ppm.setHeight(mHeight);
    ppm.setWidth(mWidth);
    ppm.setMaxColorValue(63);

    int row;
    int col;

    for (row = 0; row < ppm.getHeight(); row++) {
        for (col = 0; col < ppm.getWidth(); col++) {
            if (getNumber(row, col) == 0) {
				ppm.setPixel(row, col, 0, 0, 0);
			}

			else if (getNumber(row, col) == getMaxNumber()) {
				ppm.setPixel(row, col, 63, 31, 31);
			}

			else if (getNumber(row, col) % 8 == 0) {
				ppm.setPixel(row, col, 63, 63, 63);
			}

			else if (getNumber(row, col) % 8 == 1){
				ppm.setPixel(row, col, 63, 31, 31);	
			}

			else if (getNumber(row, col) % 8 == 2){
				ppm.setPixel(row, col, 63, 63, 31);
			}

			else if (getNumber(row, col) % 8 == 3) {
				ppm.setPixel(row, col, 31, 63, 31);
			}

			else if (getNumber(row, col) % 8 == 4) {
				ppm.setPixel(row, col, 0, 0, 0);
			}

			else if (getNumber(row, col) % 8 == 5) {
				ppm.setPixel(row, col, 31, 63, 63);
			}

			else if (getNumber(row, col) % 8 == 6) {
				ppm.setPixel(row, col, 31, 31, 63);
			}

			else if (getNumber(row, col) % 8 == 7){
				ppm.setPixel(row, col, 63, 31, 63);
			}
        }
    }
}

void NumberGrid::setPPM( PPM& ppm, const ColorTable& colors ) {
	int col;
    int row;

	if (colors.getNumberOfColors() >= 2) {
		ppm.setWidth(getWidth());
		ppm.setHeight(getHeight());
		ppm.setMaxColorValue(colors.getMaxChannelValue());
		for (row = 0; row < getHeight(); row++) {
			for (col = 0; col < getWidth(); col++) {
                if (getNumber(row, col) == getMaxNumber()) {
                    int last_index = colors.getNumberOfColors() - 1;
                    ppm.setPixel(row, col, colors[last_index].getRed(), colors[last_index].getGreen(), colors[last_index].getBlue());
                } else {
                    int index = getNumber(row, col) % colors.getNumberOfColors();
                    ppm.setPixel(row, col, colors[index].getRed(), colors[index].getGreen(), colors[index].getBlue());
                }
			}
		}
	}
}

void NumberGrid::calculateAllNumbers() {
    int row;
    int col;
    for (row = 0; row < getHeight(); row++) {
        for (col = 0; col < getWidth(); col++) {
            setNumber(row, col, calculateNumber(row, col));
        }
    }
}