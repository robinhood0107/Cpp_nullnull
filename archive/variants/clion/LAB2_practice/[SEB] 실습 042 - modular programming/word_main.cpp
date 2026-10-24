#include "word_input.h"
#include "command_handler.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    bool running = true;

    process_input();

    while (running && std::getline(std::cin, line)) {
        if (!line.empty()) {
            running = handle_command(line);
        }
    }

    return 0;
}
