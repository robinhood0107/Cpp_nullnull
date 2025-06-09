#include "word_manager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

void process_input() {
    //Implement your code
    string s;
    getline(cin,s);
    stringstream ss(s);
    string token;
    while (ss >> token && token != "^^"){
        string tmp;
        for (auto a : token){
            if (!isalnum(a)) continue;
            tmp += tolower(a);
        }
        add_word(tmp);
    }
}

