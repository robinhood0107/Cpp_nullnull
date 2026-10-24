#include <iostream>
#include "Array.hpp"
#include <stdexcept>

// Implement your code
//throw는 r-value로 하고 catch는 reference(참조자)로 받아라!! (throw 했으면 try-catch 필수임. 안하면 프로그램 죽어버림)
int main() {
    Array<int> arr(5);
    try{
    arr.at(0) = 1;
    arr.at(1) = 2;
    arr.at(2) = 3;
    arr.at(3) = 4;
    arr.at(4) = 5;
    arr.at(5) = 6;
    } catch(const std::out_of_range &e){  //외우고 있어야 하는 말 : throw는 r-value로 하고 catch는 reference(참조자)로 받아라!!
                                    //이렇게 std::exception으로 해도 되고(이걸 catch에 적으면 뭐든간에 에러만 발생하면 catch 조건 실행) std::out_of_range으로 해도 됨!!! 
                                    //catch에 조건 (out_of_range &e)으로 잡았다는 거는 예외가 out_of_range로 처리되면 예외로 넘겨주겠다는 거고
        std::cout<<e.what()<<std::endl;
        //이렇게 걍 알면 됨. what()을
    }
    return 0;
}