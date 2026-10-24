//
// Created by pjjpj on 25. 4. 1.
//


//반드시 알아야 하는 사항 = (cin >> ) 연산의 경우 EOF(\0)나 유효하지 않은 입력을 만나면 false 반환
//이래서 while 조건문 안에 쓸 수 있는거임(while 동안 EOF나 유효한거만나면 false이니까)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string line;
  vector<int> vec;
  while(cin >> line){
    getline(cin,line);
    stringstream ss(line);
    string i=0;
    int veclen=0;
    while(ss>>i){
      vec.push_back(stoi(i));
      veclen++;
    }
    /*
    string token;
    int veclen;
    while(getline(ss,token,' ')){
      if(token != ""){
      vec.push_back(stoi(token));
      veclen++;}
    }
     */
    //굉장히 번거롭고 어려운 코드니까 걍 ss >> i 써라.
    cout << veclen << " "<< *min_element(vec.begin(),vec.end()) << " "<< *max_element(vec.begin(),vec.end());
    //min max는 단 2개의 값이나 pair 값만 비교 가능
    //vector는 min_element 써야 함( 근데 반복자를 반환하니까 * 역참조 해서 꼭 요소 출력하기)


  }
}