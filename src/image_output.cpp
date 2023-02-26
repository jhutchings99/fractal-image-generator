#include <iostream>
#include <fstream>
#include <string>
#include "image_menu.h"

void drawAsciiImage(ActionData& action_data) {
    int row;
    int col;
    int channelTotal;
    double pixelStrength;

    for (row = 0; row < action_data.getOutputImage().getHeight(); row++) {
        for (col = 0; col < action_data.getOutputImage().getWidth(); col++) {
            channelTotal = action_data.getOutputImage().getChannel(row, col, 0) + action_data.getOutputImage().getChannel(row, col, 1) + action_data.getOutputImage().getChannel(row, col, 2);
            pixelStrength = channelTotal / 765.0;

            if (pixelStrength >= 1.0) {
                action_data.getOS() << '@';
            } else if (pixelStrength >= 0.9) {
                action_data.getOS() << '#';
            } else if (pixelStrength >= 0.8) {
                action_data.getOS() << '%';
            } else if (pixelStrength >= 0.7) {
                action_data.getOS() << '*';
            } else if (pixelStrength >= 0.6) {
                action_data.getOS() << '|';
            }  else if (pixelStrength >= 0.5) {
                action_data.getOS() << '+';
            } else if (pixelStrength >= 0.4) {
                action_data.getOS() << ';';
            } else if (pixelStrength >= 0.3) {
                action_data.getOS() << '~';
            } else if (pixelStrength >= 0.2) {
                action_data.getOS() << '-';
            } else if (pixelStrength >= 0.1) {
                action_data.getOS() << '.';
            } else {
                action_data.getOS() << ' ';
            }            
        }
        action_data.getOS() << std::endl;
    }
}

void writeUserImage(ActionData& action_data) {
    std::string fileName = getString(action_data, "Output filename? ");
    
    std::ofstream fout(fileName);

    action_data.getOutputImage().writeStream(fout);

    fout.close();
}

void copyImage(ActionData& action_data) {
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1( ActionData& action_data ) {
    std::string fileName = getString(action_data, "Input filename? ");

    std::ifstream fin(fileName);
    if (fin.is_open()) {
        action_data.getInputImage1().readStream(fin);
    } else {
        action_data.getOS() << "'" << fileName << "' could not be opened." << std::endl;
    }

    fin.close();
}

void readUserImage2( ActionData& action_data ) {
    std::string fileName = getString(action_data, "Input filename? ");

    std::ifstream fin(fileName);
    if (fin.is_open()) {
        action_data.getInputImage2().readStream(fin);
    } else {
        action_data.getOS() << "'" << fileName << "' could not be opened." << std::endl;
    }

    fin.close();
}

void copyImage1ToImage2(ActionData& action_data) {
    action_data.getInputImage2() = action_data.getInputImage1();
}

void copyImage2ToImage1(ActionData& action_data) {
    action_data.getInputImage1() = action_data.getInputImage2();
}