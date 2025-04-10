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
    //get()硫붿냼?쒕줈 諛쏆븘???섍꺼以섏빞 ?쒕떎.
    //洹몃━怨?蹂?섎옉 ?곌껐???꾩슂???놁씠 ?⑤룆 ?좎뼵 珥덇린???섎㈃ ??
    update(a.get(),b.get());
    cout << *a <<" " <<*b;
}



void update(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
