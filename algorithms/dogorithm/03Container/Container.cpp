#include "container.h"
#include <list>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    box_ready( ) ;
    int N = box_num( ) ;
    vector<list<int>> mysecond(N + 2);
    list<int> myfirst(N);
    iota(myfirst.begin(), myfirst.end(), 1);
    int f, s;
    while(myfirst.size() > 1){
        f = myfirst.front(); myfirst.pop_front();
        s = myfirst.front(); myfirst.pop_front();
        int temp = box_comp(f, s) == -1 ? s : f;//1이면 f가 큼, -1이면 s가 큼
        myfirst.push_back(temp);
        mysecond[temp].push_back((temp == f) ? s : f);}
    f = myfirst.front(), s = mysecond[f].front();
    mysecond[f].pop_front();
    for (auto lt : mysecond[f]) if (box_comp(lt, s) == 1) s = lt; //좀 많이 축약했는데 box_comp로 lt출력할지 s출력할지 결정하면 됨
    box_report(s);
}   

//STL 중 <numeric>헤더의 iota에 대해서 추가적으로 공부해 보고
//이런식으로도 초기화 할 수 있구나 라는 것을 찾아보았습니다

//원래는 연결리스트로 자료구조 이용해서 토너먼트식으로 분기 나누어 해결할려고 했는데
//짜보니까 queue랑 별 다른게 없는 것 같아서 stl list 사용해봤습니다.
