//
// Created by pjjpj on 25. 4. 2.
//
//STL??array??array<int,5> arr; ?대윴?앹쑝濡??대떎
// array<?먮즺?? 媛쒖닔> ?대쫫;
// 留덉갔媛吏濡?<array> 異붽? ?꾩닔
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
