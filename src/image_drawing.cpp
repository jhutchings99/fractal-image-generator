#include <iostream>
#include <cmath>
#include "image_menu.h"

void diagonalQuadPattern( ActionData& action_data  ) {
    int imageHeight = getInteger(action_data, "Image height? ");
    int imageWidth = getInteger(action_data, "Image width? ");

    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
    action_data.getInputImage1().setMaxColorValue(255);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row < action_data.getInputImage1().getHeight() / 2) {
                red = 0;
            } else {
                red = 255;
            }

            if (col < action_data.getInputImage1().getWidth() / 2) {
                blue = 0;
            } else {
                blue = 255;
            }

            green = (2*row + 2*col) % 256;

            action_data.getInputImage1().setChannel(row, col, 0, red);
            action_data.getInputImage1().setChannel(row, col, 2, blue);
            action_data.getInputImage1().setChannel(row, col, 1, green);
        }
    }
}

void stripedDiagonalPattern( ActionData& action_data ) {
    int imageHeight = getInteger(action_data, "Image height? ");
    int imageWidth = getInteger(action_data, "Image width? ");

    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
    
    int maxColorValue = (imageHeight + imageWidth) / 3;
    if (maxColorValue > 255) {
        maxColorValue = 255;
    }

    action_data.getInputImage1().setMaxColorValue(maxColorValue);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row < action_data.getInputImage1().getHeight() / 2) {
                red = 0;
            } else if (row % 3 == 0) {
                red = 0;
            } else {
                red = maxColorValue;
            }

            if (col < row ) {
                blue = 0;
            } else {
                blue = maxColorValue;
            }

            green = (row + action_data.getInputImage1().getWidth() - col - 1) % (maxColorValue + 1);

            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}

// FOUR SQUARE FUNCTION FOR EXAM 1 REVIEW
void fourSquarePattern( ActionData& action_data ) {
    int imageSize = getInteger(action_data, "Image size? ");

    action_data.getInputImage1().setHeight(imageSize);
    action_data.getInputImage1().setWidth(imageSize);
    action_data.getInputImage1().setMaxColorValue(100);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row <= action_data.getInputImage1().getHeight() / 2) {
                if (col <= action_data.getInputImage1().getWidth() / 2) {
                    red = 100;
                    green = 0;
                    blue = 66;
                }
            }

            if (row <= action_data.getInputImage1().getHeight() / 2) {
                if (col >= action_data.getInputImage1().getWidth() / 2) {
                    red = 0;
                    green = 100;
                    blue = 33;
                }
            }

            if (row >= action_data.getInputImage1().getHeight() / 2) {
                if (col <= action_data.getInputImage1().getWidth() / 2) {
                    red = 66;
                    green = 33;
                    blue = 100;
                }
            }

            if (row >= action_data.getInputImage1().getHeight() / 2) {
                if (col >= action_data.getInputImage1().getWidth() / 2) {
                    red = 33;
                    green = 66;
                    blue = 0;
                }
            }

            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}

// SIMPLE SQUARES ASCII FUNCTION FOR EXAM 1 REVIEW
void simpleSquaresPattern(ActionData& action_data) {
    int imageSize = getInteger(action_data, "Image size? ");

    action_data.getInputImage1().setHeight(imageSize);
    action_data.getInputImage1().setWidth(imageSize);
    action_data.getInputImage1().setMaxColorValue(255);


    int row;
    int col;
    int red;
    int green;
    int blue = 255;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row < action_data.getInputImage1().getHeight() / 2) {
                red = 127;
            } else {
                red = 255;
            }

            if (col < action_data.getInputImage1().getWidth() / 2) {
                green = 0;
            } else {
                green = 255;
            }

            action_data.getInputImage1().setChannel(row, col, 0, red);
            action_data.getInputImage1().setChannel(row, col, 1, green);
            action_data.getInputImage1().setChannel(row, col, 2, blue);
        }
    }
}

void flagRomaniaPattern( ActionData& action_data ) {
    int imageHeight = getInteger(action_data, "Image height? ");
    int imageWidth = (imageHeight * 3) / 2;

    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
    action_data.getInputImage1().setMaxColorValue(255);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (col < action_data.getInputImage1().getWidth() / 3) {
                red = 0;
                green = 43;
                blue = 127;
            } else if (col < (action_data.getInputImage1().getWidth() * 2) / 3) {
                red = 252;
                green = 209;
                blue = 22;
            } else {
                red = 206;
                green = 17;
                blue = 38;
            }
            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}

void flagColumbiaPattern( ActionData& action_data ) {
    int imageHeight = getInteger(action_data, "Image height? ");
    int imageWidth = (imageHeight * 3) / 2;

    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
    action_data.getInputImage1().setMaxColorValue(255);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row ++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row < action_data.getInputImage1().getHeight() / 2) {
                red = 252;
                green = 209;
                blue = 22;
            } else if (row >= action_data.getInputImage1().getHeight() / 2 && row < action_data.getInputImage1().getHeight() - (action_data.getInputImage1().getHeight() / 4)) {
                red = 0;
                green = 56;
                blue = 147;
            } else {
                red = 206;
                green = 17;
                blue = 38;
            }
            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}

void setSize( ActionData& action_data ) {
    int imageHeight = getInteger(action_data, "Height? ");
    int imageWidth = getInteger(action_data, "Width? ");

    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
}

void setMaxColorValue( ActionData& action_data ) {
    int maxColorVal = getInteger(action_data, "Max color value? ");

    action_data.getInputImage1().setMaxColorValue(maxColorVal);
}

void setChannel( ActionData& action_data ) {
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int channel = getInteger(action_data, "Channel? ");
    int value = getInteger(action_data, "Value? ");

    action_data.getInputImage1().setChannel(row, column, channel, value);
}

void setPixel( ActionData& action_data ) {
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");

    action_data.getInputImage1().setPixel(row, column, red, green, blue);
}

void clearAll( ActionData& action_data ) {
    int row;
    int col;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            action_data.getInputImage1().setPixel(row, col, 0, 0, 0);
        }
    }
}

void drawCircle(ActionData& action_data) {
    int centerRow = getInteger(action_data, "Center Row? ");
    int centerCol = getInteger(action_data, "Center Column? ");
    int radius = getInteger(action_data, "Radius? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");

    int row;
    int col;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (std::sqrt(((row - centerRow) * (row - centerRow)) + ((col - centerCol) * (col - centerCol))) <= radius) {
                action_data.getInputImage1().setPixel(row, col, red, green, blue);
            }
        }
    }
}

void drawBox(ActionData& action_data) {
    int topRow = getInteger(action_data, "Top Row? ");
    int leftCol = getInteger(action_data, "Left Column? ");
    int bottomRow = getInteger(action_data, "Bottom Row? ");
    int rightCol = getInteger(action_data, "Right Column? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");

    int row;
    int col;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row >= topRow && row <= bottomRow && col >= leftCol && col <= rightCol) {
                action_data.getInputImage1().setPixel(row, col, red, green, blue);
            }
        }
    }
}

void drawSquare(ActionData& action_data) {
    int row = getInteger(action_data, "Row? ");
    int col = getInteger(action_data, "Column? ");
    int size = getInteger(action_data, "Size? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue? ");

    int topRow = row - (size / 2);
    int leftCol = col - (size / 2);
    int bottomRow = row + (size / 2);
    int rightCol = col + (size / 2);

    int row2;
    int col2;

    for (row2 = 0; row2 < action_data.getInputImage1().getHeight(); row2++) {
        for (col2 = 0; col2 < action_data.getInputImage1().getWidth(); col2++) {
            if (row2 >= topRow && row2 <= bottomRow && col2 >= leftCol && col2 <= rightCol) {
                action_data.getInputImage1().setPixel(row2, col2, red, green, blue);
            }
        }
    }
}

void drawTestColorPattern(ActionData& action_data) {
    int height = getInteger(action_data, "Height? ");
    int width = getInteger(action_data, "Width? ");
    int maxColorVal = getInteger(action_data, "Max color value? ");

    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(maxColorVal);

    int row;
    int col;
    int red;
    int green;
    int blue;

    for (row = 0; row < action_data.getInputImage1().getHeight(); row++) {
        for (col = 0; col < action_data.getInputImage1().getWidth(); col++) {
            if (row <= action_data.getInputImage1().getHeight() / 2 && col < action_data.getInputImage1().getWidth() / 2) {
                red = maxColorVal;
                green = 0;
                blue = 0;
            }

            if (row <= action_data.getInputImage1().getHeight() / 2 && col >= action_data.getInputImage1().getWidth() / 2) {
                red = 0;
                green = maxColorVal;
                blue = 0;
            }

            if (row >= action_data.getInputImage1().getHeight() / 2 && col < action_data.getInputImage1().getWidth() / 2) {
                red = 0;
                green = 0;
                blue = maxColorVal;
            }


            if (row >= action_data.getInputImage1().getHeight() / 2 && col >= action_data.getInputImage1().getWidth() / 2) {
                red = maxColorVal / 2;
                green = maxColorVal / 2;
                blue = maxColorVal / 2;
            }

            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}

void configureGrid(ActionData& action_data) {
    int gridHeight = getInteger(action_data, "Grid Height? ");
    int gridWidth = getInteger(action_data, "Grid Width? ");
    int maxColorVal = getInteger(action_data, "Grid Max Value? ");

    action_data.getGrid().setGridSize(gridHeight, gridWidth);
    action_data.getGrid().setMaxNumber(maxColorVal);
}

void setGrid(ActionData& action_data) {
    int gridRow = getInteger(action_data, "Grid Row? ");
    int gridCol = getInteger(action_data, "Grid Column? ");
    int value = getInteger(action_data, "Grid Value? ");

    action_data.getGrid().setNumber(gridRow, gridCol, value);
}

void applyGrid(ActionData& action_data) {
    action_data.getGrid().setPPM(action_data.getOutputImage());
}

// ColorTable functions
void setColorTableSize(ActionData& action_data) {
	int size;
	size = getInteger(action_data, "Size? ");
	action_data.getTable().setNumberOfColors(size);
}

void setColor(ActionData& action_data) {
	int red;
    int green;
    int blue;
    int position;

	position = getInteger(action_data, "Position? ");
	red = getInteger(action_data, "Red? ");
	green = getInteger(action_data, "Green? ");
	blue = getInteger(action_data, "Blue? ");

	action_data.getTable()[position].setChannel(0, red);
	action_data.getTable()[position].setChannel(1, green);
	action_data.getTable()[position].setChannel(2, blue);
}

void setRandomColor(ActionData& action_data) {
	int position;
	position = getInteger(action_data, "Position? ");
	action_data.getTable().setRandomColor(255, position);
}

void setColorGradient(ActionData& action_data) {
	int position1 = getInteger(action_data, "First position? ");
	int red1 = getInteger(action_data, "First red? ");
	int green1 = getInteger(action_data, "First green? ");
	int blue1 = getInteger(action_data, "First blue? ");

	int position2 = getInteger(action_data, "Second position? ");
	int red2 = getInteger(action_data, "Second red? ");
	int green2 = getInteger(action_data, "Second green? ");
	int blue2 = getInteger(action_data, "Second blue? ");

	Color color1(red1, green1, blue1);
    Color color2(red2, green2, blue2);

	action_data.getTable().insertGradient(color1, color2, position1, position2);
}

void applyGridColorTable(ActionData& action_data) {
    action_data.getGrid().setPPM(action_data.getOutputImage(), action_data.getTable());
}

// ComplexFraction functions
void setFractalPlaneSize(ActionData& action_data) {
    ComplexFractal* ptr = dynamic_cast<ComplexFractal*>(&action_data.getGrid());
    if (ptr != 0) {
        double minX = getDouble(action_data, "Min X? ");
        double maxX = getDouble(action_data, "Max X? ");
        double minY = getDouble(action_data, "Min Y? ");
        double maxY = getDouble(action_data, "Max Y? ");
        
        (*ptr).setPlaneSize(minX, maxX, minY, maxY);
    } else {
        action_data.getOS() << "Not a ComplexFractal object. Can't set plane size." << std::endl;
    }

}    
void calculateFractal(ActionData& action_data) {
    action_data.getGrid().calculateAllNumbers();
}

// JuliaSet functions
void setJuliaParameters(ActionData& action_data) {
    JuliaSet* ptr = dynamic_cast<JuliaSet*>(&action_data.getGrid());
    if (ptr != 0) {
        double a = getDouble(action_data, "Parameter a? ");
        double b = getDouble(action_data, "Parameter b? ");
        (*ptr).setParameters(a, b);
    } else {
        action_data.getOS() << "Not a JuliaSet object. Can't set parameters." << std::endl;
    }
}

void setMandelbrotPower(ActionData& action_data) {
    MandelbrotPower* ptr = dynamic_cast<MandelbrotPower*>(&action_data.getGrid());
    if (ptr != 0) {
        double power = getDouble(action_data, "Power? ");
        (*ptr).setPower(power);
    } else {
        action_data.getOS() << "Not a MandelbrotPower object. Can't set power." << std::endl;
    }
}

void zoomPlane(ActionData& action_data) {
    ComplexFractal* ptr = dynamic_cast<ComplexFractal*>(&action_data.getGrid());
    if (ptr != 0) {
        double zoomFactor = getDouble(action_data, "Zoom Factor? ");
        
        (*ptr).zoomPlane(zoomFactor);
    } else {
        action_data.getOS() << "Not a ComplexFractal object. Can't zoom plane." << std::endl;
    }
}

void setInvertedColorGradient(ActionData& action_data) {
    int firstPosition = getInteger(action_data, "First position? ");
	int firstRed = getInteger(action_data, "First red? ");
    int firstGreen = getInteger(action_data, "First green? ");
    int firstBlue = getInteger(action_data, "First blue? ");
    int secondPosition = getInteger(action_data, "Second position? ");

    Color color1(firstRed, firstGreen, firstBlue);

	action_data.getTable().insertInvertedGradient(color1, firstPosition, secondPosition);
}

void calculateFractalSingleThread(ActionData& action_data) {
    action_data.getGrid().NumberGrid::calculateAllNumbers();
}

void setHueSaturationValueGradient(ActionData& action_data) {
    int firstPosition = getInteger(action_data, "First position? ");
    double firstHue = getDouble(action_data, "First hue? ");
    double firstSaturation = getDouble(action_data, "First saturation? ");
    double firstValue = getDouble(action_data, "First value? ");

    int secondPosition = getInteger(action_data, "Second position? ");
    double secondHue = getDouble(action_data, "Second hue? ");
    double secondSaturation = getDouble(action_data, "Second saturation? ");
    double secondValue = getDouble(action_data, "Second value? ");

    Color color1;
    Color color2;

    color1.setFromHSV(firstHue, firstSaturation, firstValue);
    color2.setFromHSV(secondHue, secondSaturation, secondValue);

    action_data.getTable().insertHueSaturationValueGradient(color1, color2, firstPosition, secondPosition);
}