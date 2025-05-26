#include "Cell.h"
#include <iomanip>
#include <sstream>


Cell::Cell() : type_{CellType::STRING}, stringVal_{""}, intVal_{0}, doubleVal_{0.0} {}


// Implement your code


// private:
// CellType type_;
// std::string stringVal_;
// int intVal_;
// double doubleVal_;


//초기화 리스트는 생성자만 가능한데, 여기서는 Cell::Cell만 생성자인데, 매개변수가 다양하니까(다형성) 그거 전부 초기화 리스트 가능하다.

Cell::Cell(const std::string val): type_{CellType::STRING},stringVal_{val},intVal_{0},doubleVal_{0} {}
Cell::Cell(int val): type_{CellType::INT},stringVal_{""},intVal_{val},doubleVal_{0}{}
Cell::Cell(double val): type_{CellType::DOUBLE},stringVal_{""},intVal_{0},doubleVal_{val}{}


bool Cell::isNumeric() const {
    return this->type_ == CellType::DOUBLE || this->type_ == CellType::INT;
}
bool Cell::isString() const {
    return this->type_ == CellType::STRING;
}
double Cell::getNumericValue() const {
    if (this->type_ == CellType::DOUBLE ) {
        return doubleVal_;
    }
    else if (this->type_ == CellType::INT){
        return intVal_;
    }
    else
        return 0.0;
}
std::string Cell::toString() const {
    if (this->type_ == CellType::STRING ) {
        return stringVal_;
    }
    if (this->type_ == CellType::INT){
        return std::to_string(intVal_);
        // 꼭 std::to_string 이 함수를 반드시 사용해라 이건 외워 가기
    }

    // 내가 여기를 못했음.
    //여기서 무조건 출력을 해줘야 함. 출력은  stringstream ss; ss << ~~~ ss.str(); 이런방식으로 꼭 작성해라
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << doubleVal_;
    return ss.str();
}