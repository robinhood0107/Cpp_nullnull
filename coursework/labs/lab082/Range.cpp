#include "Range.hpp"

//Implement your code

Range::Range(long long stop): start_{0},stop_{stop},step_{1}{
    //0~stop까지 리스트 생성
    this->start_++;
}

Range::Range(long long start, long long stop): start_{start},stop_{stop},step_{1}{
    //start~stop까지 리스트 생성
    this->start_++;
}

Range::Range(long long start, long long stop, long long step): start_{start},stop_{stop},step_{step}{
    //start~stop까지 step으로 리스트 생성
    this->start_++;
}



Range::Iterator Range::begin() const {
    return Iterator(start_, step_, stop_);
    //이런 방식으로 이터레이터 객체에 start_ step_ stop_ 값을 넣어주는 거임!!!!
}

Range::Iterator Range::end() const {
    return Iterator(stop_, step_, stop_);
}