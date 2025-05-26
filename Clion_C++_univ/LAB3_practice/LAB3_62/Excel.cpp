#include "Excel.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>


// Implement your code

//여기는 좀 외워라

Excel::Excel(const Table& data) : data_{data}{}

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const {
    //일단 table 내부에 string이 있는지 검증
    //있으면 0.0 내보내고 종료
    if(hasStringInRange(fromRow,fromCol,toRow,toCol)) return 0.0;

    //이후 average
    //누적합 함수 accumulate 사용할 때 (시작, 끝, 시작매개변수(여기서 매개변수)(0이면 int,여기서 0.0 이면 0.0 double), 람다함수(적용함수))
    auto cells = getCellsInRange(fromRow, fromCol, toRow, toCol);

    auto sum = std::accumulate(cells.begin(),cells.end(),[](double acc, auto cell) {
        return acc + cell.getNumericValue();
    });

    return sum / cells.size();
}
std::string Excel::display() const{
    //여기서 아까 작성했던 stringstream toString을 사용함

    //toStirng에서 string이면 0.0, int면 int, double의 소수점 출력부분을 담당함(이걸 위해 toString을 짠 것)
    std::stringstream ss;
    for (auto li : data_) {
        for (auto elem : li) {
            ss << elem.toString() << ' ';
        }
        ss << '\n';
    }
    return ss.str();
}



// private:
std::vector<Cell> Excel::getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    //가공하기 좋게 1차원 배열로 바꿔주는 함수
    std::vector<Cell> ret;
    for (int i=fromRow-1,i<toRow;i++) {
        for (int j=fromCol-1,i<toCol;i++) {
            ret.push_back(data_[i][j]);
        }
    }
    return ret;
}
bool Excel::hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    //https://0xffffffff.tistory.com/42
    //https://koreatopclass.tistory.com/15
    //배열 안을 검사할때는 항상 any_of 나 all_of를 사용한다
    //
    //all_of (시작, 끝, 람다함수(하나라도 틀린 부분이 있다면 false 그 이외에는 true, 그리고 empty일경우 false)) -->
    //any_of  (이거는 조건에 하나라도 만족한다면 true, 그 외에는 false)


    //범위 안에 있는지 보는 것이므로
    //string 인 것이 1개라도 있으면 true;
    auto cells = getCellsInRange(fromRow, fromCol, toRow, toCol);

    return std::any_of(cells.begin(),cells.end(),[](auto cell) {
        return cell.isString();
    });
}
bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const{
    int rowsize=data_.size();
    int colsize=data_[0].size();
    return (fromRow > 1 && toRow <= rowsize+1) && (fromCol > 1 && toCol <= colsize+1);
}