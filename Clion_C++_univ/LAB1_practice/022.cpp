//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
//vector濡?2李⑥썝 諛곗뿴 留뚮뱶??嫄?2媛吏媛 ?덉쓬
vector<vector<int>> vec;
vec.resize(2,(vector<int>(5,0)));
//?대젃寃??섎㈃ 2*5???됰젹 留뚮뱾?댁쭚


    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
          cout << vec[i][j];
          }
        cout << endl;
      }




}
