//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <memory>
using namespace std;

int main(){
    int N=0;
    cin >> N;
    int* arr = new int[N];
    //이게 스마트 포인터 선언 정석임
    //그냥 다른 표현 말고 위의 표현을 암기해서 사용하자
    for(int i=0; i<N; i++){
      cin >> arr[i];
      }

    for(int j=0;j<N; j++){
      cout << arr[N-j-1] << " ";
      }
    delete [] arr;








}