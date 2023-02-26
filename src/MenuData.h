#ifndef _MENU_DATA_H
#define _MENU_DATA_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "ActionData.h"

typedef void (*ActionFunctionType)(ActionData& action_data);

class MenuData {
    public:
        MenuData();
        void addAction(const std::string& name, ActionFunctionType func, const std::string& description);
        const std::vector<std::string>& getNames() const;
        ActionFunctionType getFunction(const std::string& name);
        const std::string& getDescription(const std::string& name);

    protected:
        std::vector<std::string> mCommands;
        std::map<std::string,ActionFunctionType> mNameToFunction;
        std::map<std::string,std::string> mNameToDescription;
};

#endif /* _MENU_DATA_H */