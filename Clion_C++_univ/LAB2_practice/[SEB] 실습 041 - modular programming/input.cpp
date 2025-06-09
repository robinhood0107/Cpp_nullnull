#include "input.h"
#include "bmi_manager.h"
#include <sstream>
#include <iostream>
using namespace std;

bool run_command(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;

    // Implement your code
    if (cmd =="CREATE"){
            int count, weight, height;
            if (!(iss >> count)){
                return false;
            }
            for (int i; i < count; ++i){
                if (!(iss >> weight >> height)){
                    return false;
                }
                add_bmi(weight,height);
            }
            return true;
        
    }
    else if (cmd == "PRINT"){
            show_bmi();
            return true;
        
    }
    else if (cmd == "DELETE"){
            int value;
            if(!(iss >> value)){
                return false;
            }
            iss >> value;
            drop_value(value);
            return true;
        
    }
    else if (cmd == "QUIT"){
            cout << "Bye!" << endl;
            return false;
        
    }
    
}
