#ifndef LED_Monitor_h
#define LED_Monitor_h
#include <iostream>
#include "OutputDevice.h"
#include "Monitor.h"


class LED_Monitor : public Monitor{
    public:
        LED_Monitor(){
            std::cout << "LED_Monitor constructor" << std::endl;
        }
        ~LED_Monitor(){
            std::cout << "LED_Monitor destructor" << std::endl;
        }
};


#endif // LED_Monitor_h