#include "word_input.h"
#include "command_handler.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, size_t> words;
    string line;
    bool running = true;

    processInput(words);

    while (running && getline(cin, line)) {
        if (!line.empty()) {
            running = processCommand(words, line);
        }
    }

    return 0;
}
