// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    //동전 0
    //동전 배열(배열길이(.size)가 동전개수)
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>> k;
    vector<int> vec(15);
    //참고)vector 2차원 선언은 vec.resize(N,(vector<int>(M,0)))
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    //DP로 풀면 시간초과(O(NK))
    //그리디로 풀어야 된다
    //가장 높은 액면가를 제일 많이 쓰고, 그 다음 액면가를 제일 많이 쓰고... 이런 방식으로 풀면 된다

    //그리고 기억할 것은 vector는 size 쓰고 string이 length 씀씀
    int cnt=0;
    for(int i = n-1; i>=0; i--){
        cnt += k/vec[i];
        k  = k%vec[i];
    }
    cout << cnt;
    return 0;
}

// 이런 문제는 무조건 cin 쓰셈
// 이 문제는 \n으로 숫자 나누어 들어오는데 절때 쓰면 안되는게 getline
// 이거 쓰면 한줄만 받아와서 바로 안됨 (이렇게 "\n"인 문제는 무조건 cin 쓰셈)
// string s;
// getline(cin,s);
// stringstream ss(s);
// string token;
// while(ss >> i{
//     vec.push_back(stoi(token));
// }