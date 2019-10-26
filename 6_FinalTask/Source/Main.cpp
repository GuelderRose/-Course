#include"DailyPlanner.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <exception>
#include <sstream>

int main() {
    Database db;
    std::string command;
    try {
        while (std::getline(std::cin, command)) {
            std::string type_of_command;
            std::stringstream input(command);
            input >> type_of_command;
            if (type_of_command == "Add") {
                CallAddEvent(db, input);
            }
            if (type_of_command == "Del") {
                CallDeleteEventOrData(db, input);
            }
            if (type_of_command == "Find") {
                CallFind(db, input);
            }
            if (type_of_command == "Print") {
                db.Print();
            }
            if (type_of_command == "") continue;
            if (type_of_command != "" && type_of_command != "Add" &&
                type_of_command != "Del" && type_of_command != "Find"
                && type_of_command != "Print") {
                std::stringstream message;
                message << "Unknown command: " << type_of_command;
                throw std::runtime_error(message.str());
            }
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
    return 0;
}