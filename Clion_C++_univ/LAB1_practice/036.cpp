




// <map> 헤더 필요함
//map 선언법 꼭 제대로 알아둬라
//map은 key value이고 {key,value}의 pair로 값이 들어간다.
//pair 값을 반드시 .insert()로 넣어야 함
//map<string,string> A; 일때 A[key] = value; 이게 가능하다
//A[key] = value;
//A.insert({key,value});
//map은 중복 허용 안하고 반복문으로 순회 가능!!!(범위지정이거 외워가)

//매우매우매우매우 중요
//while(cin >> M && M != "QUIT") 이렇게 입력이랑 종료 동시에 받는거 반드시 외워가라

//+++매우매우매우매우 중요
//find()함수로 찾으면 해당값의 "반복자" 반환함 그리고 찾지 못하면 end() 반환
//그래서 find로 찾은거는  ->  멤버포인트접근해야 한다!!!!!!!!!!

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  int N;
  cin >>N;
  string name;
  string number;
  map<string,string> phonebook;
  for(int i =0; i<N;i++){
      cin >> name >> number;
      phonebook[name] = number;
    }

  string M;
  while(cin >> M && M != "QUIT"){
      auto find = phonebook.find(M);
      if(find != phonebook.end())
        cout << find->second << endl;
      else
        cout << "NOT FOUND";
  }
}