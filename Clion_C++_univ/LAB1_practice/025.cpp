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
    //resize濡??덊븯怨?李⑤?濡?諛쏆븘?ㅻ젮硫??대젃寃?cin?쇰줈 鍮좊Ⅴ寃?諛쏆븘?ㅼ옄
    //?닿굅 洹몃깷 ?몄슦硫????대젃寃?arr1???됲겕湲곕? 吏?뺥븷 ???덉쓬.
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
