//
// Created by pjjpj on 25. 4. 2.
//
//STL의 array는 array<int,5> arr; 이런식으로 쓴다
// array<자료형, 개수> 이름;
// 마찬가지로 <array> 추가 필수
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    array<int,10> arr;
    for (auto& lt :arr){
      cin >> lt;
      }

    sort(arr.begin(),arr.end());

    cout << arr[0] <<" "<< arr[9];

  }
