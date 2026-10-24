//
// Created by pjjpj on 25. 4. 2.
//
// 벡터에서 remove의 경우 특정 수를 전부 지워버림
//erase의 경우 ()에 인덱스를 넣어서 특정 인덱스를 지우거나 erase(시작,끝) 시작~끝까지 지움
//erases는 삭제 후 다음 원소를 가리키는 이터레이터 반환
//remove는 지우고 난 후 의미없는 공간의 첫 주소의 이터레이터
//그래서 remove는 erases와 항상 함께 써서 의미없는 공간 전부 지워야됨

//암기 =  vec.erase(remove(vec.begin(),vec.end(),지우고싶은 수),vec.end())
//auto start = vec1.begin();
//    vec1.erase(start+M);
//이런거도 가능한거도 알고 있어라.
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