//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
//vector로 2차원 배열 만드는 건 2가지가 있음
vector<vector<int>> vec;
vec.resize(2,(vector<int>(5,0)));
//이렇게 하면 2*5의 행렬 만들어짐


    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
          cout << vec[i][j];
          }
        cout << endl;
      }




}