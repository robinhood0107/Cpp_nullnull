#include "input.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    bool running = true;

    while (running) {
        std::getline(std::cin, line);
        if (!line.empty()) {
            running = run_command(line);
        }
    }

    return 0;
}
