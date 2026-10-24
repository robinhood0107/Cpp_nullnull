//
// Created by pjjpj on 25. 4. 2.
//


//이 2개 전부 다 iterator을 사용함

//istream_iterator ostream_iterator 꼭 암기하기

//istream_iterator<int> cin_iter(cin); 이렇게 선언하고 (이거 그대로 암기)
//istream_iterator<int> eos; //끝을 체크하는 용도로 eos만들기

//vector에 입력받는법
//copy()함수를 사용한다
//copy(cin_iter,eos,back_inserter(vec))
//back_inserter를 통해서 순차적으로 vec 끝에 정수를 추가한다.



//ostream_iterator cout_iter(cout," ") 이렇게 선언함 (이거 그대로 암기

//출력은 copy()로 한다. copy(vec.begin(),vec.end(),cout_iter) 이렇게 하면 된다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


int main(){
      istream_iterator<int> cin_iter(cin);
      istream_iterator<int> eos;
      vector<int> vec = {};

      copy(cin_iter,eos,back_inserter(vec));
      sort(vec.begin(),vec.end());

      ostream_iterator<int> cout_iter(cout);
      copy(vec.begin(),vec.end(),cout_iter);
}