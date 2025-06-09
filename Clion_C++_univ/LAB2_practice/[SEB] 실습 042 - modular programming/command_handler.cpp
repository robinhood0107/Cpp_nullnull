#include "word_manager.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


bool handle_command(const std::string& line) {
    istringstream iss(line);
    string cmd, wd;
    size_t cnt;
    iss >> cmd >> wd >> cnt;

    //Implement your code
    if(cmd == "FIND"){
        find_word(wd);
        return true;
    }
    else if (cmd == "UPDATE"){
        update_word(wd,cnt);
        return true;
    }
    else if (cmd == "DELETE"){
        delete_word(wd);
        return true;
    }
    else if (cmd == "PRINT"){
        print_words();
        return true;
    }
    else if (cmd == "QUIT"){
        cout << "Bye!";
        return false;
    }
}
