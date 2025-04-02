//
// Created by pjjpj on 25. 4. 1.
//
#include <iostream>
using namespace std;

void my_swap(int& m,int& n);

int main() {
    int m, n;
    std::cin >> m >> n;
    my_swap(m, n);
    std::cout << m << " " << n;

}

void my_swap(int& m,int& n){
    int tmp=n;
    n = m;
    m = tmp;
}