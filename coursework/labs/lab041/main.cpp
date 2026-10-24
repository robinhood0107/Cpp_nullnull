#include "input.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> bmis;
    std::string line;
    bool running = true;

    while (running) {
        std::getline(std::cin, line);
        if (!line.empty()) {
            running = processCommand(bmis, line);
        }
    }

    return 0;
}
