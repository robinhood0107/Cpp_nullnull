//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){

    int arr_num(0);
    int quest_num(0);

    cin >> arr_num >> quest_num;

    vector<vector<int>> arr1(arr_num);
    //resize로 안하고 차례로 받아오려면 이렇게 cin으로 빠르게 받아오자
    //이거 그냥 외우면 됨 이렇게 arr1의 행크기를 지정할 수 있음.
    for (int i=0; i<arr_num; i++){
        int cnt;
        cin >> cnt;
        for (int j=0; j< cnt; j++){
            int elem;
            cin >> elem;
            arr1[i].push_back(elem);
        }
    }


    int s(0);
    int t(0);

    for (int i=0; i<quest_num; i++){
        cin >> s >> t;
        cout << arr1[s][t] << "\n";
    }

}