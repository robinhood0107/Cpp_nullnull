#include "Excel.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <sstream> // stringstream 사용을 위해 추가


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

//내가 이걸 못했음, 이렇게 소수점표현방식의 분리는 toString에서 전부 처리하고 여기선 stringstream으로 간단하게 처리하는 것.
std::string Excel::display() const {
  std::stringstream ss;

  for (auto li : data_) {
    for (auto elem : li) {
      ss << elem.toString() << ' ';
    }
    ss << '\n';
  }

  return ss.str();
}
    
    
std::vector<Cell> Excel::getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const {
    //가공하기 쉽게 2차원을 1차원 배열로 바꿔주는 함수라고 생각하면 된다.
    std::vector<Cell> ret;
    // 인덱스 범위 체크
    size_t rowsize = data_.size();
    size_t colsize = rowsize > 0 ? data_[0].size() : 0;
    if (fromRow < 1 || fromCol < 1 || toRow > static_cast<int>(rowsize) || toCol > static_cast<int>(colsize))
        return ret;
    for (int i = fromRow - 1; i < toRow; i++) {
        for (int j = fromCol - 1; j < toCol; j++) {
            ret.push_back(data_[i][j]);
        }
    }
    return ret;
}
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

bool Excel::hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    auto cells = getCellsInRange(fromRow,fromCol,toRow,toCol);
        
    return any_of(cells.begin(),cells.end(),[](auto cell){
        return cell.isString();
    });
}
//bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const{
//    int rowsize= data_.size();
//    int colsize= data_[0].size();
//    return (fromRow > 1 && toRow <= rowsize+1) && (fromCol > 1 && toCol <= colsize+1);
//}
bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const {
    if (data_.empty() || data_[0].empty()) return false;
    int rowsize = data_.size(); //원래 정석대로 하면 static_cast<int>(data_.size())으로 들어가야 함.
    int colsize = data_[0].size(); // 위와 마찬가지다.
    return (fromRow >= 1 && toRow <= rowsize && fromRow <= toRow) &&
        (fromCol >= 1 && toCol <= colsize && fromCol <= toCol);
}