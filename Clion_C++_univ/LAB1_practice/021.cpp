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
    //?닿쾶 ?ㅻ쭏???ъ씤???좎뼵 ?뺤꽍??
    //洹몃깷 ?ㅻⅨ ?쒗쁽 留먭퀬 ?꾩쓽 ?쒗쁽???붽린?댁꽌 ?ъ슜?섏옄
    for(int i=0; i<N; i++){
      cin >> arr[i];
      }

    for(int j=0;j<N; j++){
      cout << arr[N-j-1] << " ";
      }
    delete [] arr;








}
