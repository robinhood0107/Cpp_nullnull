#ifndef OutputDevice_h
#define OutputDevice_h
#include <iostream>

class OutputDevice{
    public:
        OutputDevice(){
            std::cout << "OutputDevice constructor" << std::endl;
        }
        ~OutputDevice(){
            std::cout << "OutputDevice destructor" << std::endl;
        }
};

#endif // OutputDevice_h