#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>

static std::vector<std::vector<int>> board;

void init_board() {
    board = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
}

const std::vector<std::vector<int>>& get_board() {
    return board;
}

int count_full_lines() {
//count_if 와 all_of를 이용해서 열비교
    //이건 그대로 암기해주면 됨 헤더파일은 algorithm

    //count_if(시작,끝)는 벡터에서 람다함수에 맞는 수 를 카운팅해서 개수 반환
    //all_of(시작,끝,람다)는 범위 내 모든 원소가 조건 만족하면 true, 그렇지 않으면 false 반환
    //샌다(모든(원소가 1))
    return std::count_if(board.begin(),board.end(),[](auto li){
        return std:: all_of(li.begin(), li.end(), [](auto elem) {
            return elem == 1;
        });
    });

    // 이렇게 return 겹쳐 쓰는거 암기
}
void remove_full_lines() {
    //remove_if --> 삭제할 요소를 컨테이너 뒤쪽으로 옮기고 옮긴 뒤 쓰레기값(삭제할 요소) 바로 앞에 반복자 반환.
    //remove_if도 아직 뒤가 삭제 안된거니까 삭제 꼭 하기
    auto to_remove = remove_if(board.begin(),board.end(),[](auto li) {
       return all_of(board.begin(),board.end(),[](auto elem) {
           return elem == 1;
       });
    });

    int cnt = distance(to_remove,board.end());
    //distance 함수는 총 2개 인자 받고 first에서 end까지 길이 반환(진짜 순서 거리 반환이라 그냥 이것처럼 삭제된 요소 수로 사용해도 된다.

    board.erase(to_remove, board.end());

    std::vector<std::vector<int>> new_line(cnt, std::vector<int>(board[0].size(),0));
    board.insert(borad.begin(),new_line.begin(),new_line.end());
    // insert(위치, 시작, 끝)

    // fill 함수는 fill(vec.begin(),vec.end(),원하는 수); 이렇게 사용할 수 있음(algorithm 헤더)
    //이거 resize로 vec.resize(행,vector<int>(열,0))이렇게 해도 된다똑같음
}
std::vector<int> get_heights() {
    vector<int> heights{0,1,2,3,4};//각 열 번호 배열
    transform(heights.begin(), heights.end(), heights.begin(),[](auto col) {
        auto lt = find_if(board.begin(),board.end(), [col](auto row) {
            return row[col] == 1; //이건 그냥 이대로 암기해주자 transform첫
        });
        return (it == board.end()) ? 0 :(board.end()-lt);
            // find_if함수는 (시작, 끝, 함수) ->못찾으면 end()반환 ->찾으면 이터레이터)
    });
    return heights;
     //transform(시작,끝,저장할 위치,함수)
    //항이 2개면 transform(시작,끝,시작2,저장할 위치,함수(파라미터 2개))

}

int count_empty() {
    //accumulate <-- 이거 그냥 합 구하는 함수다 !!!!
        // 여기서는 그냥 내부적으로 사용할 int acc랑 이터레이터 li 선언해서 li에서 0을 카운팅 해서 넣는 방식으로 코딩함)
    return accumulate(board.begin(), board.end(),0,[](int acc, auto li) {
        return acc + count(li.begin(),li.end(),0);
    });
}

//Implement your code


