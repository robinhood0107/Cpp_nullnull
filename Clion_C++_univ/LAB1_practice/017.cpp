//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <iostream>
#include <memory>

using namespace std;



void update(int* a, int* b);

int main(){
    unique_ptr<int> a{new int};
    unique_ptr<int> b{new int};
    cin >> *a >> *b;
    //get()메소드로 받아서 넘겨줘야 한다.
    //그리고 변수랑 연결할 필요도 없이 단독 선언 초기화 하면 됨
    update(a.get(),b.get());
    cout << *a <<" " <<*b;
}



void update(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}