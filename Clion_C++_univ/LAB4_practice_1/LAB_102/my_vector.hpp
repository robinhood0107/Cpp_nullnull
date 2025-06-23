#ifndef Vector
#define Vector
#include <vector>
#include <algorithm>
// Implement your code

template <typename T>
class my_vector {

    //여기서 중요한건!! 기본생성자던지 복사생성자던지 무조건 전부 다 _data를 new T[_size]로 초기화 시켜야만 한다!!!!!! (이거 꼭 기억해 전부 초기화 필수임 반드시)
    //일부러 초기화리스트 안썼으니까 제대로 익히자.
public:
    explicit my_vector(size_t N=0) noexcept : _size{N} {
        _data = new T[_size];
    }
    ~my_vector() { //잊지말고 무조건 소멸자도 반드시 지정
        delete [] _data;
    }

    my_vector(std::initializer_list<int> lst) noexcept : _size{lst.size()} {
        _data = new T[_size];
        //이것도 걍 copy로 넣어버리면 됨 list니까
        std::copy(lst.begin(),lst.end(),_data);

        //생성자는 return 필요 없음!!!
    }

    my_vector(const my_vector<T>& other) noexcept {
        // 복사 생성자 생성하는데 반드시 other의 멤버변수 끌어와서 여기에 저장해줘야 함
        _size = other.size();
        _data = new T[_size];
        //복사 생성자는 무조건 new의 경우 copy 무조건 쓴다고 생각하면 됨, copy의 경우는 (시작, 끝, 저장할 위치)
        std::copy(other._data,other._data+other.size(),_data); //이렇게 억지로 지정해줘야 함 begin end 못쓴다
    }
    T& operator[](int i) {
        return *(_data+i); //항상 T&는 배열이면 이걸로 반환한다 //data[i] 항상 이걸로 반환한다고 생각!!!
    }
    [[nodiscard]] size_t size() const {
        return _size;
        //위에서 other의 사이즈 연결시킬 때 필요함
    }
private:
    size_t _size;
    T* _data;
};




#endif