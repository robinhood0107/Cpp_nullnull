#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <map>
#include <string>

enum class CommandType {
    FIND,
    UPDATE,
    DELETE,
    PRINT,
    QUIT
};

bool processCommand(std::map<std::string, size_t>& words, const std::string& line);
CommandType parseCommand(const std::string& command);

#endif
