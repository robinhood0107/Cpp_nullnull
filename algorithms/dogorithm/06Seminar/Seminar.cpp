#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(){
    //각 챕터는 인덱스로 구분된다고 보면 된다
    //여기서 배열에 들어가는 숫자는 해당 챕터번호(인덱스)에서의 페이지수 
    //그리고 한 사람이 챕터를 맡을 때는 반드시 연속된 인덱스를 가져야 한다(그럼 이걸 검사하면 되나?)
    //즉 모든 경우의 수에서 가장 많이 부담하는 사람의 분량이 최소가 되는 경우의 수를 찾아서 확인하면 된다는 것
    int N,k,mid,result; //챕터 수랑 회원 수, 이분탐색용 중간값
    cin >> N >> k;
    vector<int> vec(N);
    for (int& pages : vec) cin >> pages;
    int mymin = *max_element(vec.begin(),vec.end()); //가장 페이지 수 많은 페이지로 누군가는 이걸 맡아야 함.
    int mymax = accumulate(vec.begin(),vec.end(),0); //1명이 전부 부담하면 이 값이 stdout으로 나올것임 //stl 최대한 활용
    while(mymin <= mymax){
        mid = (mymin+mymax)/2;
        int sumtemp=0; int cnt=1;
        for(int lt: vec){//책 분배로 이분탐색 넘어가면 다음, 아니면 계속 분배
            if(sumtemp + lt > mid){
                cnt++;
                sumtemp = lt;}
            else sumtemp += lt;}
        if (cnt<=k){//mid 조정
            result = mid;
            mymax = mid-1;
        } 
        else mymin = mid+1; 
}
    cout << result;
    return 0;
}