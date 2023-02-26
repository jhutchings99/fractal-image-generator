#ifndef _IMAGE_MENU_H
#define _IMAGE_MENU_H
#include <iostream>
#include <string>
#include "Image.h"
#include "PPM.h"
#include "ActionData.h"
#include "MenuData.h"
#include "ComplexFractal.h"
#include "JuliaSet.h"
#include "MandelbrotSet.h"
#include "BurningShip.h"

// Questions 3
std::string getString( ActionData& action_data, const std::string& prompt );
int getInteger( ActionData& action_data, const std::string& prompt );
double getDouble( ActionData& action_data, const std::string& prompt );
int askQuestions3(ActionData& action_data);
int assignment1( std::istream& is, std::ostream& os );

// ASCII Image
void drawAsciiImage(ActionData& action_data);
void diagonalQuadPattern( ActionData& action_data );
int assignment2( std::istream& is, std::ostream& os );

// Image file
void writeUserImage(ActionData& action_data);
void stripedDiagonalPattern( ActionData& action_data );
int assignment3( std::istream& is, std::ostream& os );

// Four square exam 1 review
void fourSquarePattern( ActionData& action_data );
int four_square( std::istream& is, std::ostream& os );

// Simple squares ascii exam 1 review
void simpleSquaresPattern(ActionData& action_data);
int simple_squares_ascii(std::istream& is, std::ostream& os);

// Hero exam 1 review
int askHeroQuestions(ActionData& action_data);
int hero( std::istream& is, std::ostream& os );

// Exam 1 question
void flagRomaniaPattern( ActionData& action_data );
int flag_romania( std::istream& is, std::ostream& os );

// Exam 1 question
int askUncleBuckQuestions(ActionData& action_data);
int buck( std::istream& is, std::ostream& os );

// Exam 1 question
void flagColumbiaPattern( ActionData& action_data );
int flag_columbia_ascii(std::istream& is, std::ostream& os);

// PPM Menu
std::string getChoice( ActionData& action_data );
void commentLine( ActionData& action_data );
void quit(ActionData& action_data);
void setSize( ActionData& action_data );
void setMaxColorValue( ActionData& action_data );
void setChannel( ActionData& action_data );
void setPixel( ActionData& action_data );
void clearAll( ActionData& action_data );
void copyImage(ActionData& action_data);
void readUserImage1( ActionData& action_data );
void showMenu( MenuData& menu_data, ActionData& action_data );
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);
void configureMenu( MenuData& menu_data );
int imageMenu(std::istream& is, std::ostream& os);

// PPM Operators
void plusEquals( ActionData& action_data );
void minusEquals( ActionData& action_data );
void timesEquals( ActionData& action_data );
void divideEquals( ActionData& action_data );
void plus( ActionData& action_data );
void minus( ActionData& action_data );
void times( ActionData& action_data );
void divide( ActionData& action_data );
void readUserImage2( ActionData& action_data );
void grayFromRed(ActionData& action_data);
void grayFromGreen(ActionData& action_data);
void grayFromBlue(ActionData& action_data);
void grayFromLinearColorimetric(ActionData& action_data);
void drawCircle(ActionData& action_data);
void drawBox(ActionData& action_data);

// EXAM 2 FUNCTIONS
void orangeFilter(ActionData& action_data);
void drawSquare(ActionData& action_data);
void timesEqualsPPM(ActionData& action_data);
void copyImage1ToImage2(ActionData& action_data);
void copyImage2ToImage1(ActionData& action_data);
void drawTestColorPattern(ActionData& action_data);
void blendImages(ActionData& action_data);

// NumberGrid
void configureGrid(ActionData& action_data);
void setGrid(ActionData& action_data);
void applyGrid(ActionData& action_data);

// ColorTable
void setColorTableSize(ActionData& action_data);
void setColor(ActionData& action_data);
void setRandomColor(ActionData& action_data);
void setColorGradient(ActionData& action_data);
void applyGridColorTable(ActionData& action_data);

void setBetterGradient(ActionData& action_data); //new stuff


// ComplexFractal
void setFractalPlaneSize(ActionData& action_data);
void calculateFractal(ActionData& action_data);

// JuliaSet
void setJuliaParameters(ActionData& action_data);
void setComplexFractal( ActionData& action_data );
void setJuliaFractal( ActionData& action_data );

// MandelbrotSet
void setMandelbrotFractal( ActionData& action_data );

void setMandelbrotPower(ActionData& action_data);
void setMandelbrotPowerFractal(ActionData& action_data);

void setJuliaFourFractal(ActionData& action_data);

void zoomPlane(ActionData& action_data);

void setInvertedColorGradient(ActionData& action_data);

void calculateFractalSingleThread(ActionData& action_data);

// BurningShip
void setBurningShipFractal( ActionData& action_data );

void setHueSaturationValueGradient(ActionData& action_data);

#endif /* _IMAGE_MENU_H */