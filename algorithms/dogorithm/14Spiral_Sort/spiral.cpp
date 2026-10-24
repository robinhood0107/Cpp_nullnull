#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);
    vector<long long> x(n), y(n);
    vector<int> all;

    for (int i = 0; i < n; i++) {
        cin >> num[i] >> x[i] >> y[i];
        all.push_back(i);
    }

    vector<bool> done(n, false);

    long long cx = 0, cy = 0;
    long long dx = 1, dy = 0;

    for (int step = 0; step < n; step++) {
        vector<int> cand;

        // copy_if --> 이거 stl중에서 원래 벡터에서 조건을 만족하는 원소만 골라 새 벡터에 복사하는 것
        copy_if(all.begin(), all.end(), back_inserter(cand), [&](int i) {
            return !done[i];
        });

        int best = -1;
        int bestPart = 0;
        long long bestCross = 0, bestDot = 0, bestD = 0;

        for (int i : cand) {
            long long vx = x[i] - cx;
            long long vy = y[i] - cy;
            long long cross = dx * vy - dy * vx;
            long long dot = dx * vx + dy * vy;
            long long dist = vx * vx + vy * vy;

            int part;
            if (cross == 0 && dot > 0) part = 0;
            else if (cross > 0) part = 1;
            else if (cross == 0 && dot < 0) part = 2;
            else part = 3;

            bool pick = false;
            if (best == -1) pick = true;
            else if (part < bestPart) pick = true;
            else if (part == bestPart) {
                if (part == 1 || part == 3) {
                    long double cmp = (long double)dot * bestCross - (long double)cross * bestDot;
                    if (cmp > 0) pick = true;
                    else if (cmp == 0 && dist < bestD) pick = true;
                } else if (dist < bestD) {
                    pick = true;
                }
            }

            if (pick) {
                best = i;
                bestPart = part;
                bestCross = cross;
                bestDot = dot;
                bestD = dist;
            }
        }

        cout << num[best] << '\n';
        done[best] = true;

        dx = x[best] - cx;
        dy = y[best] - cy;
        cx = x[best];
        cy = y[best];
    }

    return 0;
}
