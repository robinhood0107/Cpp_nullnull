#ifndef MY_ACCUMULATE_HPP
#define MY_ACCUMULATE_HPP
// Implement your code

template<typename T, typename U> 
U my_accumulate(const T& begin, const T& end, const U& init){
    T start = begin;;
    U temp = init;
    while(start != end){
        temp += *start;
        start++; //이게 왜 ++가 작동하는지 알아두기
    }
    return temp;
}



#endif //MY_ACCUMULATE_HPP
