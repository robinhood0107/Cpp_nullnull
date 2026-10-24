#ifndef LCD_Monitor_h
#define LCD_Monitor_h
#include <iostream>
#include "OutputDevice.h"
#include "Monitor.h"

class LCD_Monitor : public Monitor{
    public:
        LCD_Monitor(){
            std::cout << "LCD_Monitor constructor" << std::endl;
        }
        ~LCD_Monitor(){
            std::cout << "LCD_Monitor destructor" << std::endl;
        }
};


#endif // LCD_Monitor_h
