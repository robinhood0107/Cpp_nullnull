#include "command_handler.h"
#include "word_manager.h"
#include <sstream>
#include <iostream>

using namespace std;

CommandType parseCommand(const string& cmd) {
    if (cmd == "FIND")
        return CommandType::FIND;
    else if (cmd == "UPDATE")
        return CommandType::UPDATE;
    else if (cmd == "DELETE")
        return CommandType::DELETE;
    else if (cmd == "PRINT")
        return CommandType::PRINT;
    else if (cmd == "QUIT")
        return CommandType::QUIT;

}

bool processCommand(map<string, size_t>& words, const string& line) {
    istringstream iss(line);
    string command, wd;
    size_t cnt; //size_t
    iss >> command >> wd >> cnt;
    switch (parseCommand(command)) {
    case CommandType::FIND:
        findWord(words, wd);
        return true;
    case CommandType::UPDATE:
        updateWord(words, wd, cnt);
        return true;
    case CommandType::DELETE:
        deleteWord(words, wd);
        return true;
    case CommandType::PRINT:
        printWords(words);
        return true;
    case CommandType::QUIT:
        cout << "Bye!";
        return false;
    }
}
