#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <memory>
#include <sstream>
#include <stdexcept>

// Implement your code

template<typename T> 
class Array{
public:
    Array(size_t size=0) : _size{size} {
        _data = new T[_size];
        //new 자료형[길이] 이거 꼭 기억!
    }

    ~Array(){
        delete [] _data;
        //해제 무조건 해라
    }

    T& at(size_t index){
        if(index >= _size || index < 0){
            std::stringstream ss;
            ss << "Out of Range error: " << index;
            throw std::out_of_range(ss.str()); //std::out_of_range를 호출하면 예외가 발생함
            //out_of_range객체는 파라미터가(std::string)이라서 out_of_range("Out of Range error: " + std::to_string(index))도 됨 (to_string()으로 string으로 바꾸기)
            //throw는 r-value를 던저라(주소가 없는 것을 throw해야 함)(그래서 out_of_range 자체를 던지는 것)

            //throw 발생했는데 try catch를 안했다면? terminate 발생후 강제 종료 --> 걍 프로그램 죽여버림. 자원을 회수할 길이 없다. 매우 안좋음. 메모리를 회수할 수 있는 방법이 사라져 버리기 때문 
        }
        else
            return *(_data+index);
    }

private:
    size_t _size{0};
    T* _data; //포인터 미리 선언해두기
};











#endif //ARRAY_HPP