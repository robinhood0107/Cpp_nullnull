#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP
// Implement your code
#include <algorithm>

template<typename T>
class my_vector {
public:
    
//여기서 중요한건!! 기본생성자던지 복사생성자던지 무조건 전부 다 _data를 new T[_size]로 초기화 시켜야만 한다!!!!!! (이거 꼭 기억해 전부 초기화 필수임 반드시)
//일부러 초기화리스트 안썼으니까 제대로 익히자.
    
    my_vector(size_t N=0) noexcept{
        _size = N;
        _data = new T[_size];
    }
    ~my_vector() noexcept{
        delete [] _data;
    }
    my_vector(std::initializer_list<int> lst) noexcept{
        _size = lst.size();     //초기화 꼭
        _data = new T[_size];   //초기화 꼭
        std::copy(lst.begin(),lst.end(),_data);
        //생성자는 return이 없다
    }
    my_vector(const my_vector<T>& other) noexcept{
        //복사생성자지만 여기서는 
        _size = other._size;     //초기화 꼭
        _data = new T[_size];   //초기화 꼭
        std::copy(other._data, other._data + _size, _data); //이렇게 표현한다는 점 꼭 기억
    }
    T& operator[](int i){
        return *(_data+i); //_data[i]이거랑 같은 소리다.
    }
    size_t size() const{
        return _size;
    }



// (선택) begin(), end() 지원하려면 이렇게 하면 된다.
    // const T* begin() const { return _data; }
    // const T* end() const { return _data + _size; }

// (시험에는 절대 안나옴)참고로 복사 대입 연산자는 이렇게 함
    /*
        my_vector& operator=(const my_vector<T>& other) noexcept {
            if (this != &other) {
                delete[] _data;
                _size = other._size;
                _data = new T[_size];
                std::copy(other._data, other._data + _size, _data);
            }
            return *this;
        }
    */
    
private:
    size_t _size;
    T* _data;
};




#endif //MY_VECTOR_HPP