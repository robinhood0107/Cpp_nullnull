//
// Created by pjjpj on 25. 4. 1.
//
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <string>
using namespace std;

std::vector<int> read_input(int n);
std::pair<int, int> calc_sums(const std::vector<int>& numbers);

int main() {
    int N;
    std::cin >> N;

    std::vector<int> numbers = read_input(N);
    std::pair<int, int> result = calc_sums(numbers);

    std::cout << result.first << std::endl;     // Even sum
    std::cout << result.second << std::endl;    // Odd sum

    return 0;
}
//getline 2媛吏 諛⑹떇 ?꾨? 吏쒓린
//stringstream? stringstream ss(?먮? 寃?;?대윴?앹쑝濡??⑥닔泥섎읆
//洹몃━怨?ss>>i ?닿굅 議곌굔臾몄뿉 ?ｌ쑝?ㅻ㈃ while?⑤씪
//vector??string??int濡?諛붽??뚮뒗 臾댁“嫄?stoi ?곌린

//?묎렐? 臾댁“嫄?first, second
//pair ?좎뼵踰?臾댁“嫄??몄슦怨??덉뼱??pair<int, int> p(a,b); (?대젃寃??섍굅??
//pair<int, int> p = {a,b}; ?대젃寃??대룄 ??
vector<int> read_input(int n){
    string line;
    getline(cin,line);
    string i;
    stringstream ss(line);
    vector<int> vec;
    while(ss >> i){
        vec.push_back(stoi(i));
    }
    return vec;
}

//嫄?蹂???좎뼵?섍퀬 珥덇린???듦?泥섎읆 臾댁“嫄??섍린
pair<int, int> calc_sums(const vector<int>& numbers){
  pair<int,int> p = {0,0};
  int even=0;
  int odd=0;
  for(const auto& lt : numbers){
    if (lt%2 == 0){
      even += lt;
      }
    else
      odd += lt;
    }
  p.first = even;
  p.second = odd;
    return p;
}
