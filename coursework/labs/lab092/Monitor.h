#ifndef Monitor_h
#define Monitor_h
#include <iostream>
#include "OutputDevice.h"

class Monitor : public OutputDevice{
    public:
        Monitor(){
            std::cout << "Monitor constructor" << std::endl;
        }
        ~Monitor(){
            std::cout << "Monitor destructor" << std::endl;
        }
};


#endif // Monitor_h