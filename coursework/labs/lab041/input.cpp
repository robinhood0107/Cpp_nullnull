// Implement your code
#include "input.h"
#include "bmi.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

Command parseCommand(const std::string& cmdStr) {
    if (cmdStr == "CREATE") {
        return Command::CREATE;
    }
    else if (cmdStr == "PRINT") {
        return Command::PRINT;
    }
    else if (cmdStr == "DELETE") {
        return Command::DELETE;
    }
    else if (cmdStr == "QUIT") {
        return Command::QUIT;
    }
    else {
        return Command::UNKNOWN;
    }
}

bool processCreateCommand(std::vector<int>& bmis, std::istringstream& iss) {
    int count, weight, height;
    if (!(iss >> count)) {
        return false;
    }
    for (int i = 0; i < count; ++i) {
        if (!(iss >> weight >> height)) {
            return false;
        }
        addBMI(bmis, weight, height);
    }
    return true;
}

bool processDeleteCommand(std::vector<int>& bmis, std::istringstream& iss) {
    int del;
    if (!(iss >> del)) {
        return false;
    }
    iss >> del;
    deleteByValue(bmis, del);
    return true;
}

bool processCommand(std::vector<int>& bmis, const std::string& commandLine) {
    string cmd;
    int cnt;
    istringstream iss(commandLine);
    iss >> cmd;
    switch (parseCommand(cmd)) {
    case Command::CREATE:
        processCreateCommand(bmis, iss);
        return true;
    case Command::PRINT:
        displayBMIs(bmis);
        return true;
    case Command::DELETE:
        processDeleteCommand(bmis, iss);
        return true;
    case Command::QUIT:
        cout << "Bye!" << endl;
        return false;
    case Command::UNKNOWN:
        return true;
    }
    return true;
}