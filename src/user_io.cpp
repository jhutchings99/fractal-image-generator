#include <iostream>
#include <string>
#include "image_menu.h"

std::string getString( ActionData& action_data, const std::string& prompt ) {
    std::string userString;
    action_data.getOS() << prompt;
    action_data.getIS() >> userString;
    return userString;
}

int getInteger( ActionData& action_data, const std::string& prompt ) {
    int userInt;
    action_data.getOS() << prompt;
    action_data.getIS() >> userInt;
    return userInt;
}

double getDouble( ActionData& action_data, const std::string& prompt ) {
    double value;
    action_data.getOS() << prompt;
    action_data.getIS() >> value;
    return value;
}

int askQuestions3(ActionData& action_data) {
    std::string userString = getString(action_data, "What is your favorite color? ");
    int userInt = getInteger(action_data, "What is your favorite integer? ");
    double userDouble = getDouble(action_data, "What is your favorite number? ");
    int i;
    for (i = 0; i < userInt; i++) {
        action_data.getOS() << i+1 << " " << userString << " " << userDouble << std::endl;
    }
    return userInt;
}

int askHeroQuestions(ActionData& action_data) {
    std::string userString = getString(action_data, "Who is your hero? ");
    int userInt = getInteger(action_data, "What year were they born? ");

    action_data.getOS() << userString << " was born in " << userInt << "." << std::endl;
    return userInt;
}

int askUncleBuckQuestions(ActionData& action_data) {
    std::string userLives = getString(action_data, "Where do you live? ");
    std::string userOwner = getString(action_data, "Own or rent? ");
    int userQuestions = getInteger(action_data, "What is your record for consecutive questions asked? ");

    if (userOwner == "rent") {
        action_data.getOS() << userQuestions << " is pretty good. " << "Enjoy renting in the " << userLives << "." << std::endl;
    } else {
        action_data.getOS() << userQuestions << " is okay. " << "Enjoy owning in the " << userLives << "." << std::endl;    
    }
    return userQuestions;
}

std::string getChoice( ActionData& action_data ) {
    return getString(action_data, "Choice? ");
}

void commentLine( ActionData& action_data) {
    unsigned char c;

    while (action_data.getIS().good() && c != '\n') {
        action_data.getIS().read((char *)&c, sizeof(c));
    }
}

void quit(ActionData& action_data) {
    action_data.setDone();
}