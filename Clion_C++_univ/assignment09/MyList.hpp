//#ifndef MyList_H
//#define DEPARTMENT_H
#pragma once
//#pragma once 이거로 해도 됨. 표준은 아닌데, "헤더 파일이 컴파일 시 한 번만 포함되도록 지시하는 전처리기 지시자" 이고 GCC, Clang, MSVC에서 취급하는 사실상 표준임 //그리고 실제로 많이 사용함
#include <algorithm>
#include <complex>
// template <typename T, size_t N> 반드시 이렇게 사용! N은 size_t만 들어오니까!!
template<typename T, size_t N> //주의!!!! 우리는 지금 N의 경우는 size_t로 자료형이 확실히 정해져 있음!!!!! template <typename T,typename N> 이렇게 하면 안됨
class MyList{
    //짜기 힘들면 면서 템플릿 없다고 생각하고 클래스를 구현하면 됨.
public:
    MyList(){
        //당연하겠지만 일단 동적할당 메모리 선언 해줘야지 // 포인터 = new 자료형[길이] 이거 잊지마셈
        _data = new T[N];
        }
    ~MyList() noexcept {
        delete[] _data;
    }//Destructor that deallocates memory.
    MyList(const MyList& rhs) noexcept {
        //deep copy니까 copy() stl 무조건 사용해야됨 사용 안하면 얕은 복사되서 "포인터"만 복사되서 서로 같은데이터를 2개가 가리켜서 의미가 사라지는 거임

        // 바람직한 복사대입 하는 법
        // 기존에 _data가 가리키던 메모리 해제 (복사 대입시 필요)
        // 크기를 정확히 지정해서 새 메모리 할당
        // deep copy: 원본(rhs) 데이터를 temp로 복사
        // 이제 _data가 temp를 가리킴. temp는 delete하면 안 됨! // 이게 중요하다!!!
        // temp는 더이상 delete할 필요 없음! _data가 이 메모리를 계속 사용!
        delete[] _data;
        T* temp = new T[N];
        std::copy(rhs.begin(),rhs.end(),temp); //이렇게 copy(시작, 끝, 저장할 장소)
        _data = temp;
        pos = rhs.pos; // (내가 틀린 부분) 이거 무조건 해줘야 함!!!
        //내가 여길 틀림... 당연히 pos도 복사해줘야지!!!!
    }//Copy constructor (deep copy).

    MyList& operator=(const MyList& rhs) {
    //여기도 마찬가지로 당연히 deep copy
        delete[] _data;
        T* temp = new T[N];
        std::copy(rhs.begin(),rhs.end(),temp);
        _data = temp;
        pos = rhs.pos; // (내가 틀린 부분) 이거 무조건 해줘야 함!!!
        //내가 여길 틀림... 당연히 pos도 복사해줘야지!!!!
        return *this;
    }//- 연산자 오버로딩에서 `operator=()`은 **자기 자신에 대한 참조(`*this`)를 반환**해야 합니다.
    //그래야 `a = b = c;`처럼 **연쇄 할당**이 자연스럽게 됩니다.

    void add(T& data) {
        //add랑 remove에서 계속 pos로 현재 위치를 알려줘야 함
        if (pos < N) {     // 아직 공간이 있을 때만
            _data[pos] = data; //_data 백터에 string이던지 int던지 data 자체가 1개의 원소로 1칸당 1개 들어가는 것
            ++pos;         // pos 값 할당(증가)! //그니깐 pos++만 해주면 됨
        }
    }//Adds an element to the list if space permits.


    void remove(T& data) {
        // 1. 배열에서 data와 같은 값을 찾음
        for (int i = 0; i < pos; ++i) {
            if (_data[i] == data) {
                // 2. 찾았다면 그 위치(i) 이후의 모든 값을 한 칸씩 앞으로 당김
                //    즉, i+1부터 pos-1까지 왼쪽으로 한 칸씩 복사
                for (int j = i; j < pos - 1; ++j) {
                    _data[j] = _data[j+1];
                }
                // 3. 데이터 개수(pos)를 1 감소시켜 마지막 값이 더 이상 사용되지 않음을 표시
                --pos;
                break; // 같은 값이 여러 개여도 한 번만 삭제하고 종료
            }
        }
    }// 존재하면 원소를 제거하고, 남은 항목들을 앞으로 이동시킵니다.

    T* begin(){
        return _data;
    }

    const T* begin() const{
        return _data;
    }//Iterator to the first element.

    T* end(){
        //- `pos`는 현재 저장된 데이터의 개수입니다.
        //- 데이터 배열: `_data[0] ~ _data[pos-1]`에 실제 데이터 저장
        //- `"마지막 데이터 이후의 위치"` → `_data + pos`
        return _data + pos;
    }
    const T* end() const {
        return _data + pos;
    }
private:
    T* _data{nullptr}; //Pointer to the array of type T.
    int pos{0}; //Index to track the number of elements stored.
}; //이 세미콜론을 잊지마라 class는 세미콜론 무조건!!!!!!!!


//#endif