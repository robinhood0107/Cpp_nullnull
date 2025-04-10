//
// Created by pjjpj on 25. 4. 1.
//
//??蹂대윭媛湲곗쟾???닿굅 諛섎뱶???붽린
/*
int n;
int size;
int* arr = new int[size];

delete
*
*/
// new "?먮즺?? <-?닿쾶 ?먮옒 new瑜??곕뒗 諛⑸쾿?대떎
// 諛곗뿴 ?댁젣?좊븣??諛섎뱶??delete [] arr; ?대윴?앹쑝濡??대씪

// ?숈쟻蹂???좎뼵?대떎 ?ъ씤?곌? ?꾨땲??
//?숈쟻 蹂?섎땲源??뱀뿰??(?숈쟻) 蹂???좎뼵?쒕떎怨??앷컖?댁빞 ??
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
