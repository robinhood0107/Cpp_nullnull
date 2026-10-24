#include "invert.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, N, d, L, H;
string S, T;
vector<int> sa, pos_arr, tmp, lcp;

bool cmp(int i, int j) {
    if (pos_arr[i] != pos_arr[j]) return pos_arr[i] < pos_arr[j];
    i += d; j += d;
    return (i < n && j < n) ? pos_arr[i] < pos_arr[j] : i > j;
}

void build() {
    n = T.length();
    sa.resize(n); pos_arr.resize(n); tmp.resize(n); lcp.resize(n);
    for(int i=0; i<n; i++) sa[i] = i, pos_arr[i] = T[i];
    
    for(d=1; ; d*=2) {
        sort(sa.begin(), sa.end(), cmp);
        for(int i=0; i<n-1; i++) tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        for(int i=0; i<n; i++) pos_arr[sa[i]] = tmp[i];
        if(tmp[n-1] == n-1) break;
    }
    
    for(int i=0, h=0; i<n; i++) {
        if(!pos_arr[i]) continue;
        int j = sa[pos_arr[i]-1];
        while(i+h < n && j+h < n && T[i+h] == T[j+h]) h++;
        lcp[pos_arr[i]] = h;
        if(h) h--;
    }
}

bool chk(int k, int &bi, int &bj) {
    int Cmin = N-H-2*k+2, Cmax = N-L-2*k+2;
    bi = 1e9; bj = -1; bool f = 0;
    vector<int> A, B;
    
    for(int u=0, v=0; u<n; u=v+1) {
        v = u;
        while(v+1 < n && lcp[v+1] >= k) v++;
        A.clear(); B.clear();
        for(int m=u; m<=v; m++) {
            int p = sa[m];
            if(p < N) A.push_back(p+1);
            else if(p > N && p <= 2*N) B.push_back(p-N);
        }
        
        sort(B.begin(), B.end());
        for(int i : A) {
            auto it = upper_bound(B.begin(), B.end(), Cmax-i);
            if(it != B.begin() && *(it-1) >= Cmin-i) {
                f = 1; int j = *(it-1);
                if(i < bi || (i == bi && j > bj)) bi = i, bj = j;
            }
        }
    }
    return f;
}

InvertedRepeat find_inverted_repeat(const string& sequence, int minimum_gap, int maximum_gap) {
    S = sequence;
    L = minimum_gap;
    H = maximum_gap;
    if (L < 0 || H < L) return {};
    N = S.length();
    
    string Sr = S;
    reverse(Sr.begin(), Sr.end());
    T = S + '\2' + Sr + '\1';
    
    build();
    
    int l=1, r=N/2, ans=0, fbi=0, fbj=0;
    while(l <= r) {
        int m = (l+r)/2, bi, bj;
        if(chk(m, bi, bj)) ans = m, fbi = bi, fbj = bj, l = m+1;
        else r = m-1;
    }

    if (!ans) return {};
    return {fbi, fbi+ans-1, N-fbj-ans+2, N-fbj+1};
}

#ifndef INVERT_NO_MAIN
int main() {
    int minimum_gap, maximum_gap;
    if (!(cin >> minimum_gap >> maximum_gap) || minimum_gap < 0 || maximum_gap < minimum_gap) {
        cerr << "0 <= L <= H 조건의 두 정수를 입력하세요.\n";
        return 1;
    }
    ifstream input("S.txt");
    if (!input) {
        cerr << "현재 작업 폴더에 S.txt가 필요합니다.\n";
        return 1;
    }
    string sequence, part;
    while (input >> part) sequence += part;
    const auto result = find_inverted_repeat(sequence, minimum_gap, maximum_gap);
    if (!result.left_begin) cout << "0\n";
    else cout << result.left_begin << ' ' << result.left_end << ' '
              << result.right_begin << ' ' << result.right_end << '\n';
}
#endif
