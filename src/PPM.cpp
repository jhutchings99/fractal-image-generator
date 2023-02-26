#include "PPM.h"
#include <iostream>
#include <fstream>

PPM::PPM() : Image(), mMaxColorValue(1) {
}

PPM::PPM( const int& height, const int& width ) : Image(height, width), mMaxColorValue(1) {
}

int PPM::getMaxColorValue( ) const {
    return mMaxColorValue;
}

bool PPM::valueValid( const int& value ) const {
    if (value < 0) {
        return false;
    }

    if (value > mMaxColorValue) {
        return false;
    }

    return true;
}

void PPM::setMaxColorValue( const int& max_color_value ) {
    if (max_color_value > 0 && max_color_value <= 255) {
        mMaxColorValue = max_color_value;
    }
}

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if (valueValid(value)) {
        Image::setChannel(row, column, channel, value);
    }
}

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ) {
    setChannel(row, column, 0, red);
    setChannel(row, column, 2, blue);
    setChannel(row, column, 1, green);
}

void PPM::writeStream(std::ostream& os) const {
    int row;
    int col;
    int red;
    int green;
    int blue;
    unsigned char val;


    os << "P6 " << getWidth() << " " << getHeight() << " " << getMaxColorValue() << "\n";

    for (row = 0; row < getHeight(); row++) {
        for (col = 0; col < getWidth(); col ++) {
            red = getChannel(row, col, 0);
            val = red;
            os.write((char *)&val, sizeof(val));

            blue = getChannel(row, col, 1);
            val = blue;
            os.write((char *)&val, sizeof(val));

            green = getChannel(row, col, 2);
            val = green;
            os.write((char *)&val, sizeof(val));
        }
    }
}

void PPM::readStream(std::istream& is) {
    std::string test;
    int width;
    int height;
    int maxColor;
    int row;
    int col;
    unsigned char val;

    is >> test >> width >> height >> maxColor;

    setWidth(width);
    setHeight(height);
    setMaxColorValue(maxColor);

    is.read((char *)&val, sizeof(val));

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col ++) {
            is.read((char *)&val, sizeof(val));
            setChannel(row, col, 0, val);

            is.read((char *)&val, sizeof(val));
            setChannel(row, col, 1, val);

            is.read((char *)&val, sizeof(val));
            setChannel(row, col, 2, val);
        }
    }
}

bool PPM::operator==( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 == (rhs.getHeight() * rhs.getWidth()) / 3;
}

bool PPM::operator!=( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 != (rhs.getHeight() * rhs.getWidth()) / 3;
}

bool PPM::operator<( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 < (rhs.getHeight() * rhs.getWidth()) / 3;
}

bool PPM::operator<=( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 <= (rhs.getHeight() * rhs.getWidth()) / 3;
}

bool PPM::operator>( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 > (rhs.getHeight() * rhs.getWidth()) / 3;
}

bool PPM::operator>=( const PPM& rhs ) const {
    return ((*this).getHeight() * (*this).getWidth()) / 3 >= (rhs.getHeight() * rhs.getWidth()) / 3;
}

PPM& PPM::operator+=( const PPM& rhs ) {
	int row;
	int col;
	int newVal;

	for (row = 0; row < (*this).getHeight(); row++) {
		for (col = 0; col < (*this).getWidth(); col++) {
            newVal = (*this).getChannel(row, col, 0) + rhs.getChannel(row, col, 0);
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }
            (*this).setChannel(row, col, 0, newVal);

            newVal = (*this).getChannel(row, col, 1) + rhs.getChannel(row, col, 1);
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }
            (*this).setChannel(row, col, 1, newVal);


            newVal = (*this).getChannel(row, col, 2) + rhs.getChannel(row, col, 2);
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }
            (*this).setChannel(row, col, 2, newVal);
		}
	}
	return *this;
}

PPM& PPM::operator-=( const PPM& rhs ) {
	int row;
	int col;
	int newVal;

	for (row = 0; row < (*this).getHeight(); row++) {
		for (col = 0; col < (*this).getWidth(); col++) {
            newVal = (*this).getChannel(row, col, 0) - rhs.getChannel(row, col, 0);
            if (newVal < 0) {
                newVal = 0;
            }
            (*this).setChannel(row, col, 0, newVal);

            newVal = (*this).getChannel(row, col, 1) - rhs.getChannel(row, col, 1);
            if (newVal < 0) {
                newVal = 0;
            }
            (*this).setChannel(row, col, 1, newVal);


            newVal = (*this).getChannel(row, col, 2) - rhs.getChannel(row, col, 2);
            if (newVal < 0) {
                newVal = 0;
            }
            (*this).setChannel(row, col, 2, newVal);
		}
	}
	return *this;
}

PPM& PPM::operator*=( const double& rhs ) {
	int row;
	int col;
	int newVal;

	for (row = 0; row < (*this).getHeight(); row++) {
		for (col = 0; col < (*this).getWidth(); col++) {
            newVal = (*this).getChannel(row, col, 0) * rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 0, newVal);

            newVal = (*this).getChannel(row, col, 1) * rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 1, newVal);


            newVal = (*this).getChannel(row, col, 2) * rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 2, newVal);
		}
	}
	return *this;
}

PPM& PPM::operator/=( const double& rhs ) {
	int row;
	int col;
	int newVal;

	for (row = 0; row < (*this).getHeight(); row++) {
		for (col = 0; col < (*this).getWidth(); col++) {
            newVal = (*this).getChannel(row, col, 0) / rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 0, newVal);

            newVal = (*this).getChannel(row, col, 1) / rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 1, newVal);


            newVal = (*this).getChannel(row, col, 2) / rhs;
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 2, newVal);
		}
	}
	return *this;
}

PPM PPM::operator+( const PPM& rhs ) const {
    PPM p = *this;
    p.setMaxColorValue((*this).getMaxColorValue());
    p += rhs;
    return p;
}

PPM PPM::operator-( const PPM& rhs ) const {
    PPM p = *this;
    p -= rhs;
    return p;
}

PPM PPM::operator*( const double& rhs ) const {
    PPM p = *this;
    p *= rhs;
    return p;
}

PPM PPM::operator/( const double& rhs ) const {
    PPM p = *this;
    p /= rhs;
    return p;
}

void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const {
    dst = *this;
    int row;
    int col;
    for (row = 0; row < (*this).getHeight(); row++) {
        for (col = 0; col < (*this).getWidth(); col++) {
            dst.setChannel(row, col, 0, (*this).getChannel(row, col, src_channel));
            dst.setChannel(row, col, 1, (*this).getChannel(row, col, src_channel));
            dst.setChannel(row, col, 2, (*this).getChannel(row, col, src_channel));
        }
    }
}

void PPM::grayFromRed( PPM& dst ) const {
    grayFromChannel(dst, 0);
}

void PPM::grayFromGreen( PPM& dst ) const {
    grayFromChannel(dst, 1);
}

void PPM::grayFromBlue( PPM& dst ) const {
    grayFromChannel(dst, 2);
}

double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const {
    int red = (*this).getChannel(row, column, 0);
    int green = (*this).getChannel(row, column, 1);
    int blue = (*this).getChannel(row, column, 2);
    return 0.2126*red + 0.7152*green + 0.0722*blue;
}

void PPM::grayFromLinearColorimetric( PPM& dst ) const {
    dst = *this;
    int row;
    int col;
    for (row = 0; row < dst.getHeight(); row++) {
        for (col = 0; col < dst.getWidth(); col++) {
            int value = linearColorimetricPixelValue(row, col);
            dst.setChannel(row, col, 0, value);
            dst.setChannel(row, col, 1, value);
            dst.setChannel(row, col, 2, value);
        }
    }
}

void PPM::orangeFilter(PPM& dst) const {
    dst = *this;
    int row;
    int col;
    int new_red;
    int new_green;
    int new_blue;
    int old_red;
    int old_green;
    int old_blue;

    for (row = 0; row < dst.getHeight(); row++) {
        for (col = 0; col < dst.getWidth(); col++) {
            old_red = dst.getChannel(row, col, 0);
            old_green = dst.getChannel(row, col, 1);
            old_blue = dst.getChannel(row, col, 2);

            new_red = 2*(2*old_red+old_green)/3;
            new_green = 2*(2*old_red+old_green)/6;
            new_blue = old_blue/2;

            if (new_red > dst.getMaxColorValue()) {
                new_red = dst.getMaxColorValue();
            }

            if (new_green > dst.getMaxColorValue()) {
                new_green = dst.getMaxColorValue();
            }

            if (new_blue > dst.getMaxColorValue()) {
                new_blue = dst.getMaxColorValue();
            }
            
            dst.setPixel(row, col, new_red, new_green, new_blue);
        }
    }
}

PPM& PPM::operator*=( const PPM& rhs ) {
	int row;
	int col;
	int newVal;

	for (row = 0; row < (*this).getHeight(); row++) {
		for (col = 0; col < (*this).getWidth(); col++) {
            newVal = ((*this).getChannel(row, col, 0) * rhs.getChannel(row, col, 0)) / rhs.getMaxColorValue();
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 0, newVal);

            newVal = ((*this).getChannel(row, col, 1) * rhs.getChannel(row, col, 1)) / rhs.getMaxColorValue();
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 1, newVal);


            newVal = ((*this).getChannel(row, col, 2) * rhs.getChannel(row, col, 2)) / rhs.getMaxColorValue();
            if (newVal > (*this).getMaxColorValue()) {
                newVal = (*this).getMaxColorValue();
            }

            if (newVal < 0) {
                newVal = 0;
            }

            (*this).setChannel(row, col, 2, newVal);
		}
	}
	return *this;
}