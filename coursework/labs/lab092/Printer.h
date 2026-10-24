#ifndef Printer_h
#define Printer_h
#include <iostream>
#include "OutputDevice.h"

class Printer : public OutputDevice{
    public:
        Printer(){
            std::cout << "Printer constructor" << std::endl;
        }
        ~Printer(){
            std::cout << "Printer destructor" << std::endl;
        }
};


#endif // Printer_h