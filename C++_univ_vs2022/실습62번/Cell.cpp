#include "Cell.h"
#include <iomanip>
#include <sstream>
#include <string>


Cell::Cell() : type_{CellType::STRING}, stringVal_{""}, intVal_{0}, doubleVal_{0.0} {}


// Implement your code


//public
    Cell::Cell(const std::string& val)
        : type_{CellType::STRING}, 
        stringVal_{val}, 
        intVal_{0}, 
        doubleVal_{0.0}
        {}
    Cell::Cell(int val)
        : type_{CellType::INT}, 
        stringVal_{""}, 
        intVal_{val}, 
        doubleVal_{0.0}
        {}
    Cell::Cell(double val)
        : type_{CellType::DOUBLE}, 
        stringVal_{""}, 
        intVal_{0}, 
        doubleVal_{val}
        {}
    /*
    Cell::Cell(const std::string val)
        : type_{CellType::STRING}, 
        stringVal_{val}, 
        intVal_{0}, 
        doubleVal_{0.0}
        {
            type_ = CellType::STRING;
            if (isString(this->stringVal_)){
                toString();
                stringVal_ = this->stringVal_;
            }
    }
    Cell::Cell(int val)
        : type_{CellType::INT}, 
        stringVal_{""}, 
        intVal_{val}, 
        doubleVal_{0.0}
        {
            type_ = CellType::INT;
            if (isString(this->intVal_)){
                getNumericValue();
                intVal_ = this->intVal_;
            }
    }
    Cell::Cell(double val)
        : type_{CellType::DOUBLE}, 
        stringVal_{""}, 
        intVal_{0}, 
        doubleVal_{val}
        {
            type_ = CellType::DOUBLE;
            if (isString(this->doubleVal_)){
                getNumericValue();
                doubleVal_ = this->doubleVal_;
            }
    }
    */

    bool Cell::isString() const{
        return this->type_ == CellType::STRING;
        /*
        if (!isdigit(stringVal_)){
            return true;
        }
        else 
            return false;
        */
    }
    bool Cell::isNumeric() const{
        return this->type_ == CellType::INT || this->type_ == CellType::DOUBLE;
    
        /*
        if (!isdigit(intVal_) && intVal_ != 0){
            return true;
        }
        else if(!isdigit(doubleVal_) && doubleVal_ != 0.0){
            return true;
        }
        else{
            return false;
        }
        */
    }  
    double Cell::getNumericValue() const{
        if (type_ == CellType::STRING) return 0.0;
        if (type_ == CellType::INT) return (double)intVal_;
        return (double)doubleVal_;
        /*
        if (!isdigit(intVal_) && intVal_ != 0){
            return static_cast<double>intVal_;
        }
        else if(!isdigit(doubleVal_) && doubleVal_ != 0.0){
            return doubleVal_;
        }
        else{
            return 0.0;
        }
        */
    }
    
    //내가 이 toString을 구현을 못했음 이거 제대로 공부해놓아라
    std::string Cell::toString() const {
    	if (type_ == CellType::STRING) return stringVal_;
    	if (type_ == CellType::INT) return std::to_string(intVal_);
    
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << doubleVal_;
        return ss.str();
    }