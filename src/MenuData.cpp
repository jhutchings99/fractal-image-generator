#include <iostream>
#include "image_menu.h"

MenuData::MenuData() {
}

void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string& description) {
    mCommands.push_back(name);
    mNameToFunction[name] = func;
    mNameToDescription[name] = description;

}

const std::vector<std::string>& MenuData::getNames() const {
    return mCommands;
}

ActionFunctionType MenuData::getFunction(const std::string& name) {
    if ( mNameToFunction.find(name) != mNameToFunction.end()) {
      return mNameToFunction[name];
    } else {
        return 0;
    }
}

const std::string& MenuData::getDescription(const std::string& name) {
    static std::string emptyString = "";

    if ( mNameToDescription.find(name) != mNameToDescription.end()) {
        return mNameToDescription[name];
    } else {
        return emptyString;
    }
}