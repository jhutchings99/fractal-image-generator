#include <iostream>
#include <cstdlib>
#include "ColorTable.h"
#include <math.h>

// Color class implementation

Color::Color( ) 
: mRed(0), mGreen(0), mBlue(0) {
}

Color::Color( const int& red, const int& green, const int& blue ) 
: mRed(red), mGreen(green), mBlue(blue) {
}

int Color::getRed( ) const {
    return mRed;
}

int Color::getGreen( ) const {
    return mGreen;
}

int Color::getBlue( ) const {
    return mBlue;
}

int Color::getChannel( const int& channel ) const {
    if (channel == 0) {
        return mRed;
    }

    if (channel == 1) {
        return mGreen;
    }

    if (channel == 2) {
        return mBlue;
    }

    return -1;
}

void Color::setRed( const int& value ) {
    if (value >= 0) {
        mRed = value;
    }
}

void Color::setGreen( const int& value ) {
    if (value >= 0) {
        mGreen = value;
    }
}

void Color::setBlue( const int& value ) {
    if (value >= 0) {
        mBlue = value;
    }
}

void Color::setChannel( const int& channel, const int& value ) {
    if (value >= 0) {
        if (channel == 0) {
            mRed = value;
        }
    
        if (channel == 1) {
            mGreen = value;
        }

        if (channel == 2) {
            mBlue = value;
        }
    }
}

void Color::invert( const int& max_color_value ) {
    if (max_color_value >= mRed && max_color_value >= mGreen && max_color_value >= mBlue) {
        mRed = max_color_value - mRed;
        mGreen = max_color_value - mGreen;
        mBlue = max_color_value - mBlue;
    }
    
}

bool Color::operator==( const Color& rhs ) const {
    if ((*this).getRed() != rhs.getRed()) {
        return false;
    }

    if ((*this).getGreen() != rhs.getGreen()) {
        return false;
    }

    if ((*this).getBlue() != rhs.getBlue()) {
        return false;
    }

    return true;
}

std::ostream& operator<<( std::ostream& os, const Color& color ) {
    os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
    return os;
}

// ColorTable class implementation

ColorTable::ColorTable( const int& num_color ) {
    mColors.resize(num_color);
}

int ColorTable::getNumberOfColors( ) const {
    return mColors.size();
}

void ColorTable::setNumberOfColors( const int& num_color ) {
    mColors.resize(num_color);
}

const Color& ColorTable::operator[]( const int& i ) const {
    if (i >= 0 && i < getNumberOfColors()) {
        return mColors[i];
    } else {
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
}

Color& ColorTable::operator[]( const int& i ) {
    if (i >= 0 && i < getNumberOfColors()) {
        return mColors[i];
    } else {
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
}

void ColorTable::setRandomColor( const int& max_color_value, const int& position ) {
    int random_color;
    if (position >= 0 && position < getNumberOfColors()) {
        if (max_color_value >= 0) {
        random_color = std::rand() % (max_color_value + 1);
		mColors[position].setRed(random_color);

		random_color = std::rand() % (max_color_value + 1);
		mColors[position].setGreen(random_color);

		random_color = std::rand() % (max_color_value + 1);
		mColors[position].setBlue(random_color);
        }
    }
}

double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const {
    return (y2 - y1) / (x2 - x1);
}

double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const {
    return y1 + slope * (x - x1);
}

void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ) {
    int i;

    if (position1 >= 0 && position2 >= 0 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 < position2) {
        int n = position2 - position1;

        double redStep = ( (double)color2.getRed() - color1.getRed() ) / ( n );
        double greenStep = ( (double)color2.getGreen() - color1.getGreen() ) / ( n );
        double blueStep = ( (double)color2.getBlue() - color1.getBlue() ) / ( n );

        for (i = 0; i < (n + 1); i++) {
            int newRed = color1.getRed() + i * redStep;
            int newGreen = color1.getGreen() + i * greenStep;
            int newBlue = color1.getBlue() + i * blueStep;

            mColors[position1 + i].setRed(newRed);
            mColors[position1 + i].setGreen(newGreen);
            mColors[position1 + i].setBlue(newBlue);
        }
    }
}

int ColorTable::getMaxChannelValue( ) const {
    int max = 0;
    int i;
    for (i = 0; i < getNumberOfColors(); i++) {
        if (mColors[i].getRed() > max) {
            max = mColors[i].getRed();
        }

        if (mColors[i].getGreen() > max) {
            max = mColors[i].getGreen();
        }

        if (mColors[i].getBlue() > max) {
            max = mColors[i].getBlue();
        }
    }

    return max;
}

void ColorTable::insertInvertedGradient(const Color& color1, const int& position1, const int& position2) {
    Color color2 = color1;
    color2.invert(255);
    insertGradient(color1, color2, position1, position2);
}

void HSV_to_RGB(const double& hue, const double& saturation, const double& value, double& red, double &green, double& blue) {
  /* Convert Hue, Saturation, Value to Red, Green, Blue
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
   *
   * Inputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   *
   * Outputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   */
  if(hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0) {
    red = green = blue = 0.0;
    std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
              << " hue: " << hue  << std::endl
              << " saturation: " << saturation << std::endl
              << " value: " << value << std::endl;
    return;
  }

  // chroma selects the strength of the "primary" color of the current area of the wheel
  double chroma = value * saturation;
  // hue2 selects which 60-degree wedge of the color wheel we are in
  double hue2 = hue / 60.0;
  // x selects the strength of the "secondary" color of the current area of the wheel
  double x = chroma * ( 1 - std::abs( std::fmod( hue2, 2 ) - 1 ) );
  if( hue2 >= 0 && hue2 < 1 ) {
    red = chroma;
    green = x;
    blue = 0.0;
  } else if( hue2 >= 1 && hue2 < 2 ) {
    red = x;
    green = chroma;
    blue = 0.0;
  } else if( hue2 >= 2 && hue2 < 3 ) {
    red = 0.0;
    green = chroma;
    blue = x;
  } else if( hue2 >= 3 && hue2 < 4 ) {
    red = 0.0;
    green = x;
    blue = chroma;
  } else if( hue2 >= 4 && hue2 < 5 ) {
    red = x;
    green = 0.0;
    blue = chroma;
  } else if( hue2 >= 5 && hue2 <= 6 ) {
    red = chroma;
    green = 0.0;
    blue = x;
  } else {
    red = 0;
    green = 0;
    blue = 0;
  }

  // m scales all color channels to obtain the overall brightness.
  double m = value - chroma;
  red = 255.0*( red + m );
  green = 255.0*( green + m );
  blue = 255.0*( blue + m );
}

void RGB_to_HSV(const double& red0, const double &green0, const double& blue0, double& hue, double& saturation, double& value) {
  /* Red, Green, Blue to Convert Hue, Saturation, Value
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
   *
   * Inputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   *
   * Outputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   */
  if(red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0) {
    hue = saturation = value = 0.0;
    std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
              << " red: " << red0  << std::endl
              << " green: " << green0 << std::endl
              << " blue: " << blue0 << std::endl;
    return;
  }

  double red   = red0 / 255.0;
  double green = green0 / 255.0;
  double blue  = blue0 / 255.0;

  // x_max helps identify the primary hue
  double x_max = red;
  if(green > x_max) { x_max = green; }
  if(blue > x_max) { x_max = blue; }
  value = x_max;

  double x_min = red;
  if(green < x_min) { x_min = green; }
  if(blue < x_min) { x_min = blue; }

  double chroma = x_max - x_min;

  if(chroma == 0) {
    hue = 0;
  } else if(value == red) {
    hue = 60.0 * (0 + (green - blue)/chroma);
  } else if(value == green) {
    hue = 60.0 * (2 + (blue - red)/chroma);
  } else if(value == blue) {
    hue = 60.0 * (4 + (red - green)/chroma);
  } else {
    hue = -720.0;
  }
  if(hue < 0.0) {
    hue += 360.0;
  }

  if(value == 0.0) {
    saturation = 0.0;
  } else {
    saturation = chroma/value;
  }

}

void Color::setFromHSV(const double& hue, const double& saturation, const double& value) {
    double red = getRed();
    double green = getGreen();
    double blue = getBlue();

    HSV_to_RGB(hue, saturation, value, red, green, blue);

    setRed(red);
    setGreen(green);
    setBlue(blue);
}

void Color::getHSV(double& hue, double& saturation, double& value) const {
    RGB_to_HSV(mRed, mGreen, mBlue, hue, saturation, value);
}

void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2) {
    if (position1 >= 0 && position2 >= 0 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 < position2) {
        double color1Hue, color1Saturation, color1Value;
        double color2Hue, color2Saturation, color2Value;
        color1.getHSV(color1Hue, color1Saturation, color1Value);
        color2.getHSV(color2Hue, color2Saturation, color2Value);

        double hueSlope = gradientSlope(color1Hue, color2Hue, position1, position2);
        double saturationSlope = gradientSlope(color1Saturation, color2Saturation, position1, position2);
        double valueSlope = gradientSlope(color1Value, color2Value, position1, position2);
        
        for (int i = position1; i <= position2; i++) {
            double hue = gradientValue(color1Hue, position1, hueSlope, i);
            double saturation = gradientValue(color1Saturation, position1, saturationSlope, i);
            double value = gradientValue(color1Value, position1, valueSlope, i);

            Color color;
            color.setFromHSV(hue, saturation, value);
            mColors[i].setRed(color.getRed());
            mColors[i].setGreen(color.getGreen());
            mColors[i].setBlue(color.getBlue());
        }
    }
}