#include <iostream>
#include "image_menu.h"

void plusEquals( ActionData& action_data ) {
    action_data.getInputImage1() += action_data.getInputImage2();
}

void minusEquals( ActionData& action_data ) {
    action_data.getInputImage1() -= action_data.getInputImage2();
}

void timesEquals( ActionData& action_data ) {
    double factor = getDouble(action_data, "Factor? ");
    action_data.getInputImage1() *= factor;
}

void divideEquals( ActionData& action_data ) {
    double factor = getDouble(action_data, "Factor? ");
    action_data.getInputImage1() /= factor;
}

void plus( ActionData& action_data ) {
    action_data.getOutputImage() = action_data.getInputImage1() + action_data.getInputImage2();
}

void minus( ActionData& action_data ) {
    action_data.getOutputImage() = action_data.getInputImage1() - action_data.getInputImage2();
}

void times( ActionData& action_data ) {
    double factor = getDouble(action_data, "Factor? ");
    action_data.getOutputImage() = action_data.getInputImage1() * factor;
}

void divide( ActionData& action_data ) {
    double factor = getDouble(action_data, "Factor? ");
    action_data.getOutputImage() = action_data.getInputImage1() / factor;
}

void grayFromRed(ActionData& action_data) {
    action_data.getInputImage1().grayFromRed(action_data.getOutputImage());
}

void grayFromGreen(ActionData& action_data) {
    action_data.getInputImage1().grayFromGreen(action_data.getOutputImage());
}

void grayFromBlue(ActionData& action_data) {
    action_data.getInputImage1().grayFromBlue(action_data.getOutputImage());
}

void grayFromLinearColorimetric(ActionData& action_data) {
    action_data.getInputImage1().grayFromLinearColorimetric(action_data.getOutputImage());
}

void orangeFilter(ActionData& action_data) {
    action_data.getInputImage1().orangeFilter(action_data.getOutputImage());
}

void timesEqualsPPM(ActionData& action_data) {
    action_data.getOutputImage() = action_data.getInputImage1() *= action_data.getInputImage2();   
}

void blendImages(ActionData& action_data) {
    double ratio = getDouble(action_data, "Ratio? ");
    action_data.getOutputImage() = (action_data.getInputImage1() * ratio) + (action_data.getInputImage2() * (1-ratio));
}