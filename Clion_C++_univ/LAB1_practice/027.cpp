//
// Created by pjjpj on 25. 4. 2.
//
// 踰≫꽣?먯꽌 remove??寃쎌슦 ?뱀젙 ?섎? ?꾨? 吏?뚮쾭由?
//erase??寃쎌슦 ()???몃뜳?ㅻ? ?ｌ뼱???뱀젙 ?몃뜳?ㅻ? 吏?곌굅??erase(?쒖옉,?? ?쒖옉~?앷퉴吏 吏?
//erases????젣 ???ㅼ쓬 ?먯냼瑜?媛由ы궎???댄꽣?덉씠??諛섑솚
//remove??吏?곌퀬 ?????섎??녿뒗 怨듦컙??泥?二쇱냼???댄꽣?덉씠??
//洹몃옒??remove??erases? ??긽 ?④퍡 ?⑥꽌 ?섎??녿뒗 怨듦컙 ?꾨? 吏?뚯빞??

//?붽린 =  vec.erase(remove(vec.begin(),vec.end(),吏?곌퀬?띠? ??,vec.end())
//auto start = vec1.begin();
//    vec1.erase(start+M);
//?대윴嫄곕룄 媛?ν븳嫄곕룄 ?뚭퀬 ?덉뼱??
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N(0);
    vector<int> vec1;

    cin >> N;

    for(int i(0); i<N; ++i){
        int cnt;
        cin >> cnt;
        vec1.push_back(cnt);
    }

    int O(0);
    int M(0);

    cin >> M >> O;

    auto start = vec1.begin();
    vec1.erase(start+M);

    vec1.erase(remove(vec1.begin(), vec1.end(),O),vec1.end());

    cout << vec1.size() << endl;
    for (auto& it : vec1)
        cout << it << " ";
}
