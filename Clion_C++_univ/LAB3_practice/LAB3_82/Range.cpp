#include "Range.hpp"

//Implement your code


//헤더 파일에서 연산자 오버로딩을 전부 한 상태라서 지가 알아서 ++가 호출되기 때문에 초기화 리스트만 작성

Range::Range(long long stop): start_{0},stop_{stop},step_{1}{
    //0~stop까지 리스트 생성
}

Range::Range(long long start, long long stop): start_{start},stop_{stop},step_{1}{
    //start~stop까지 리스트 생성
}

Range::Range(long long start, long long stop, long long step): start_{start},stop_{stop},step_{step}{
    //start~stop까지 step으로 리스트 생성
}


Range::Iterator Range::begin() const {
    return Iterator(start_, step_, stop_);
    //이런 방식으로 이터레이터 객체에 start_ step_ stop_ 값을 넣어주는 거임!!!!
}

Range::Iterator Range::end() const {
    return Iterator(stop_, step_, stop_);
}

// 앞에 이더레이터에도 Range:: 붙는거 명심(Range::내부의 객체니까)
