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
//getline 2가지 방식 전부 짜기
//stringstream은 stringstream ss(자를 것);이런식으로 함수처럼
//그리고 ss>>i 이거 조건문에 넣으려면 while써라
//vector에 string을 int로 바꿀때는 무조건 stoi 쓰기

//접근은 무조건 first, second
//pair 선언법 무조건 외우고 있어라 pair<int, int> p(a,b); (이렇게 하거나)
//pair<int, int> p = {a,b}; 이렇게 해도 됨
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

//걍 변수 선언하고 초기화 습관처럼 무조건 하기
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