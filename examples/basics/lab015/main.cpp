//
// Created by pjjpj on 25. 4. 1.
//
//랩 보러가기전에 이거 반드시 암기
/*
int n;
int size;
int* arr = new int[size];

delete
*
*/
// new "자료형" <-이게 원래 new를 쓰는 방법이다
// 배열 해제할때는 반드시 delete [] arr; 이런식으로 해라

// 동적변수 선언이다 포인터가 아니라
//동적 변수니까 당연히 (동적) 변수 선언한다고 생각해야 함
#include <iostream>
using namespace std;

int p015(){
    int size=0;
    cin >> size;
    int* arr = new int[size];

    int n=0;
    for(int i=0; i<size;i++){
      cin >> n;
      arr[i] = n;
    }
    int m;
    cin >> m;
    cout << arr[arr[m]];
    delete [] arr;

}