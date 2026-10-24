#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <string>

enum class Command {
    CREATE,
    PRINT,
    DELETE,
    QUIT,
    UNKNOWN
};

Command parseCommand(const std::string& cmdStr);
bool processCommand(std::vector<int>& bmis, const std::string& commandLine);

#endif // INPUT_H