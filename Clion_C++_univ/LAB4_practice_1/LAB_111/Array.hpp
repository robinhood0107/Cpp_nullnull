#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <memory>
#include <stdexcept>
//반드시 외워라 try catch throw

template<typename T>
class Array{ // 탬플릿 선언시에는 이렇게 그냥 바로 밑에 적어주면 됨
    //항상 선언은 포인터 = new 자료형[] (참고: unique_ptr을 소유권 이전시에는 반드시 get를 통해 이동(흔히 대입, 복사라고 하는 작업))(파라미터로 집어 넣을 때는 move() 사용)
    T* arr; // (내가 틀린 부분 = 포인터는 반드시 T* 이걸로 선언하세요
    size_t _size;
public:
    Array(size_t size) {
        _size = size;
        arr = new T[_size];
    };
    //throw로 rvalue(string 형태)를 던져주면 catch가 그걸 받으면 출력
    T& at(size_t index) {
        if (_size <= index  || index < 0) { // 주의!!! 나 여기서 틀림 !!! 크거나 같다다 조건 매우 잘 봐야 한다!!!!!
            throw std::out_of_range("Out of Range error: " + std::to_string(index)); // 이렇게 던지는 거다 !!! 던지는 건 항상 std::out_of_range, std::ios::failure 이렇게 던지면 된다
            //std::out_of_range를 호출하면 예외가 발생함
        }
        else
            return *(arr+index); //포인터 형식으로 넘겨주는데 여기서는 해당 원소를 출력하는 거니까 arr[index]를 반환하는거랑 똑같음 근데 이건 *(arr+index)이랑 똑같다
    }
    ~Array() {
        delete [] arr; // 반드시 이렇게 배열 해제 해주기
    }
};

#endif //ARRAY_HPP
