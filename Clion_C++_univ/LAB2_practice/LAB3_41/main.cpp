#include <iostream>
#include <vector>
#include <string>

Command parseCommand(const std::string& cmdStr);
bool processCommand(std::vector<int>& bmis, const std::string& commandLine);

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
