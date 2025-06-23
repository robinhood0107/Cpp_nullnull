#ifndef MY_ACCUMULATE
#define MY_ACCUMULATE
// Implement your code

template<typename T, typename U>
U my_accumulate(const T& begin,const T& end,const U& init) {
    T start = begin;
    U temp = init; //이게 step 같은 건너 뛸 범위를 이야기 함
    while (start != end) {
        temp += *start; //temp를 이용해서 반환시킬 껀데 temp에 *start만큼 값을 참조해서 더해주면 됨
        start++; //start를 하나씩 올려가면서 반복
    }
    return temp;
}





#endif //MY_ACCUMULATE