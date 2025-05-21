#ifndef CELL_H
#define CELL_H

#include <string>

enum class CellType {
    STRING,
    INT,
    DOUBLE
};

class Cell {
private:
    CellType type_;
    std::string stringVal_;
    int intVal_;
    double doubleVal_;
public:
    Cell();
    Cell(const std::string& val);
    Cell(int val);
    Cell(double val);

    bool isNumeric() const;
    bool isString() const;
    double getNumericValue() const;
    std::string toString() const;
};

#endif
