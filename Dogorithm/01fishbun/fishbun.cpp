#include <iostream>
#include <vector>
#include <set>

using namespace std;

void swapvector(int a, int b, vector<int>& vec){
    int temp = vec[a];
    vec[a] = -vec[b];
    vec[b] = -temp;
}

int myreverse(int headidx, int tailidx, vector<int>& vec){
    if (headidx < 0 || tailidx >= (int)vec.size() || headidx > tailidx) {
        return 0; 
    }

    int left = headidx;
    int right = tailidx;

    while (left < right) {
        swapvector(left, right, vec);
        left++;
        right--;
    }

    if (left == right) {
        vec[left] = -vec[left];
    }

    return 1;
}

bool my_is_sort(const vector<int>& v) {
    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] - v[i-1] != 1) return 0;
    }
    return 1;
}

vector<pair<int, int>> myserach(const vector<int>& a, const vector<int>& b, const vector<int>& p, int n) {
    set<pair<int, int>> s;
    for (int i : b) {
        int t = -(a[i-1]+1);
        if (-n - 1 <= t && t <= n+1) {
            int r = p[t+n+1];
            if (i <= r && r <= n) s.insert({i, r});
        }
        t = -(a[i]-1);
        if (-n-1 <= t && t <= n+1) {
            int l = p[t+n+1];
            if (1 <= l && l <= i-1) s.insert({l, i-1});
        }
    }
    return {s.begin(), s.end()};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;

    vector<vector<int>> vec1(5, vector<int>(t));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < t; j++) {
            cin >> vec1[i][j];
        }
    }

    vector<int> result(5);
    for (int i = 0; i < 5; i++) {
        int N = (int)vec1[i].size();
        vector<int> v(N + 2), idx, breakidx;

        v[0] = 0;
        v[N + 1] = N + 1;
        for (int j = 0; j < N; j++) v[j + 1] = vec1[i][j];

        if (my_is_sort(v)) {
            result[i] = 1;
            continue;
        }

        breakidx.clear();
        idx.assign(2 * N + 3, 0);
        for (int j = 1; j <= N + 1; j++) if (v[j] - v[j - 1] != 1) breakidx.push_back(j);
        for (int j = 0; j <= N + 1; j++) idx[v[j] + N + 1] = j;
        if (breakidx.size() > 4) {
            result[i] = 3;
            continue;
        }

        vector<pair<int, int>> c = myserach(v, breakidx, idx, N);
        bool found = false;

        for (int j = 0; j < (int)c.size(); j++) {
            int l = c[j].first;
            int r = c[j].second;
            myreverse(l, r, v);
            if (my_is_sort(v)) {
                result[i] = 1;
                found = true;
                myreverse(l, r, v);
                break;
            }
            myreverse(l, r, v);
        }
        if (found) continue;

        for (int j = 0; j < (int)c.size(); j++) {
            int l1 = c[j].first;
            int r1 = c[j].second;
            myreverse(l1, r1, v);

            vector<int> idx2, breakidx2;
            breakidx2.clear();
            idx2.assign(2 * N + 3, 0);
            for (int k = 1; k <= N + 1; k++) if (v[k] - v[k - 1] != 1) breakidx2.push_back(k);
            for (int k = 0; k <= N + 1; k++) idx2[v[k] + N + 1] = k;

            if (breakidx2.size() <= 4) {
                vector<pair<int, int>> c2 = myserach(v, breakidx2, idx2, N);
                for (int k = 0; k < (int)c2.size(); k++) {
                    int l2 = c2[k].first;
                    int r2 = c2[k].second;
                    myreverse(l2, r2, v);
                    if (my_is_sort(v)) {
                        result[i] = 2;
                        found = true;
                        myreverse(l2, r2, v);
                        break;
                    }
                    myreverse(l2, r2, v);
                }
            }
            myreverse(l1, r1, v);

            if (found) break;
        }
        if (!found) result[i] = 3;
    }

    for (int i = 0; i < 5; i++) {
        cout << (result[i] == 1 ? "one" : result[i] == 2 ? "two" : "over") << "\n";
    }

    return 0;
}