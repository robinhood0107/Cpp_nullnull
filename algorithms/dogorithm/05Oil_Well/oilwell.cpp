#include <algorithm>
#include "oil.h"
int main(){
    initial( );
    int N=oil_size( );
    int s=0;
    int e=N-1;
    int mid;
    //이분탐색으로 찾으면 될 것 같음
    //일단 1로 시작하는 인덱스 찾아야 하는데 이건 인덱스 올라가면서 observe()로 0이 아닌 위치를 찾으면 된다
    while(s<e){
        mid=s+(e-s)/2; //이분탐색
        if(observe(0,mid)==0)s=mid+1;
        else e=mid;}
    int tmp=s;
    //여기서 start에 해당하는 s를 알았으니까 이걸 이용해서 end에 해당하는 e를 찾아주면 됨.
    e=N-1;
    //여기서 s는 무조건 유정 안에 있는 점이라 observe(L,mid)는 0일수 없음(해도 1아니면 2다)
    while(s<e){
        mid=s+(e-s+1)/2; //이분탐색, 참고로 여기서 오른쪽으로 좀 치우쳐진 중앙값을 사용해야지 무한루프 안걸리니까 조심.(당연 위의 while문은 왼쪽 치우친 중앙값 사용함)
        if(observe(tmp,mid)==1)s=mid; //여기서 위에서 구한 유전의 시작인덱스 tmp부터 mid까지의 거리를 계산하면 됨
        else e=mid-1;}//하나씩 줄이면서 확인
    oil_report(tmp,s);
}