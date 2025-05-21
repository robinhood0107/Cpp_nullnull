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



Range::Iterator begin() const {
    start_{start};
    stop_{stop};
}
Range::Iterator end() const {
    start_{start};
    stop_{stop};
}
// step == 0: Invalid step size, cannot proceed.

// start == stop: The range contains no elements.

// step > 0 and start > stop: Cannot reach stop from start in the positive direction.

// step < 0 and start < stop: Cannot reach stop from start in the negative direction.