#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 4000000000000000000LL

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;

    vector<vector<pair<char, long long>>> vec(256);
    
    for (int i = 0; i < n - 1; ++i) {
        char u, v;
        long long w;
        cin >> u >> v >> w;
        
        // u, v는 char 타입이지만 배열의 인덱스로 들어갈 때 자동으로 숫자로 변환되는거 잊지마라(아스키 문자!)
        vec[u].emplace_back(v, w); 
        vec[v].emplace_back(u, w);
    }

    vector<long long> dist(256, INF);//벡터 최대한 길게써야 함
    
    // 우선순위 큐로 최소 힙 쓰면 된다
    using Node = pair<long long, char>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    char src;
    while (cin >> src && src != '$') { //$입력 전까지 계속 받으면 됨
        dist[src] = 0;
        pq.emplace(0, src);
    }

    // 다익스트라 알고리즘!
    while (!pq.empty()) {
        auto [d, u] = pq.top(); // 구조적 바인딩 유지하는거 잊지마라
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, w] : vec[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    long long answer_twice = 0;
    // 0부터 255까지 모든 가능한 아스키 문자를 순회
    for (int u = 0; u < 256; ++u) {
        if (vec[u].empty()) continue; // 연결된 edge이 없는 정점(vertex)는 패스
        
        for (const auto& [v, w] : vec[u]) {
            // 지금 상태 그 자체는 vector로 무방향 그래프이므로 중복 계산(u->v, v->u)을 막기 위해 u < v 조건 추가
            if (u < v) {
                answer_twice = max(answer_twice, dist[u] + dist[v] + w);
            }
        }
    }

    if (answer_twice % 2 == 0) {
        cout << answer_twice / 2 << "\n";
    } else {
        cout << answer_twice / 2 << ".5\n";
    }

    return 0;
}
