#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1000000000;

int n, maxRadius;
int station[N][4], orderIdx[N];
int ansA = INF, ansB = INF;
long long best = -1;
double PI = acos(-1);

bool cmpX(int left, int right) {
    if (station[left][1] != station[right][1]) {
        return station[left][1] < station[right][1];
    }
    return station[left][2] < station[right][2];
}

double commonArea(int left, int right) {
    double r1 = station[left][3], r2 = station[right][3];
    double dx = station[left][1] - station[right][1];
    double dy = station[left][2] - station[right][2];
    double dist = sqrt(dx * dx + dy * dy);

    if (dist >= r1 + r2) return 0;
    if (dist <= abs(r1 - r2)) {
        r1 = min(r1, r2);
        return PI * r1 * r1;
    }

    double c1 = (dist * dist + r1 * r1 - r2 * r2) / (2 * dist * r1);
    double c2 = (dist * dist + r2 * r2 - r1 * r1) / (2 * dist * r2);
    c1 = max(-1.0, min(1.0, c1));
    c2 = max(-1.0, min(1.0, c2));

    double root = (-dist + r1 + r2) * (dist + r1 - r2) * (dist - r1 + r2) * (dist + r1 + r2);
    return r1 * r1 * acos(c1) + r2 * r2 * acos(c2) - sqrt(max(0.0, root)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> station[i][0] >> station[i][1] >> station[i][2] >> station[i][3];
        orderIdx[i] = i;
        maxRadius = max(maxRadius, station[i][3]);
    }

    sort(orderIdx, orderIdx + n, cmpX);

    for (int i = 0; i < n; i++) {
        int left = orderIdx[i];
        for (int j = i - 1; j >= 0; j--) {
            int right = orderIdx[j];
            int dx = station[left][1] - station[right][1];
            int limit = station[left][3] + station[right][3];

            if (dx > station[left][3] + maxRadius) break;
            if (dx > limit || abs(station[left][2] - station[right][2]) > limit) continue;

            double area = commonArea(left, right);
            if (area <= 0) continue;

            long long key = area * 1000;
            int a = station[left][0], b = station[right][0];
            if (a > b) swap(a, b);

            if (key > best || (key == best && (a < ansA || (a == ansA && b < ansB)))) {
                best = key;
                ansA = a;
                ansB = b;
            }
        }
    }

    if (best < 0) cout << "0 0\n";
    else cout << ansA << ' ' << ansB << '\n';
}
