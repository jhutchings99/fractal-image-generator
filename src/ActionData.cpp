#include <iostream>
#include "image_menu.h"

ActionData::ActionData(std::istream& is, std::ostream& os) 
: mIstream(is), mOstream(os), mDone(false), mNumberGrid(0), mColorTable(16) {
    Color color_one(0, 255, 0);
    Color color_two(255, 0, 255);

    mColorTable.insertGradient(color_one, color_two, 0, 15);
} 

ActionData::~ActionData() {
    if (mNumberGrid != 0) {
        delete mNumberGrid;
    }
}

std::istream& ActionData::getIS() {
    return mIstream;
}

std::ostream& ActionData::getOS() {
    return mOstream;
}

PPM& ActionData::getInputImage1() {
    return mImage1;
}

PPM& ActionData::getInputImage2() {
    return mImage2;
}

PPM& ActionData::getOutputImage() {
    return mOutputImage;
}

bool ActionData::getDone() const {
    return mDone;
}

void ActionData::setDone() {
    mDone = true;
}

NumberGrid& ActionData::getGrid() {
    return *mNumberGrid;
}

void ActionData::setGrid(NumberGrid *grid) {
    if (mNumberGrid != 0) {
        delete mNumberGrid;
    }

    mNumberGrid = grid;
}

ColorTable& ActionData::getTable() {
    return mColorTable;
}