#include "Excel.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>


// Implement your code


Excel::Excel(const Table& data) : data_{data}{
    //this->data_ = data;
}

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const{
    if(hasStringInRange(fromRow,fromCol,toRow,toCol)) return 0.0;
    
    auto cells = getCellsInRange(fromRow,fromCol,toRow,toCol);
    
    double sum =accumulate(cells.begin(),cells.end(),0.0,[](double acc, auto cell){
        return acc + cell.getNumericValue();
    });
    
    return sum / cells.size();
}

std::string Excel::display() const{
    std::stringstream ss;
    for(auto& lt : data_){
        for(auto& it : lt){
            if(it.isString()){
                ss << it.toString() << "\t";
            }
            else{
                ss << std::fixed << std::setprecision(1) << it.getNumericValue() << "\t";
            }
        }
        ss << "\n";
    }
    return ss.str();
}
    
    
std::vector<Cell> Excel::getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    //가공하기 쉽게 2차원을 1차원 배열로 바꿔주는 함수라고 생각하면 된다.
    std::vector<Cell> ret;
    for(int i=fromRow-1; i<toRow;i++){
        for(int j=fromCol-1; j<toCol;j++){
            ret.push_back(data_[i][j]);
        }
    }
    return ret;
    /*
    //이건 2차원을 2차원으로(내가 처음 구현한것... 반환값 안봄....)
    rowsize=data_[0].size();
    colsize=data_.size();
    Table vec;
    for(int i=fromRow-1; i<toRow;i++){
        for(int j=fromCol-1; j<tocol;j++){
            vec[toRow-i][tocol-j] = data_[i][j];
        }
    }
    return vec;
    */
}
bool Excel::hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    auto cells = getCellsInRange(fromRow,fromCol,toRow,toCol);
        
    return any_of(cells.begin(),cells.end(),[](auto cell){
        return cell.isString();
    });
}
bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const{
    int rowsize=data_[0].size();
    int colsize=data_.size();
    return (fromRow > 1 && toRow <= rowsize+1) && (fromCol > 1 && toCol <= colsize+1);
}