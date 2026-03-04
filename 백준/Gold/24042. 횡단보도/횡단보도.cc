#include <iostream>
#include <queue>
#define SIZE 100000
#define INF 9876543219876543L
#define ll long long

using namespace std;

vector<pair<int, int>> edges[SIZE];
priority_queue<pair<ll, int>> pq;

ll visited[SIZE] = {0};

int main() {
    ll dist, nd;
    int N, M, a, b, d;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        visited[i] = INF;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        
        edges[a].emplace_back(i, b);
        edges[b].emplace_back(i, a);
    }
    
    pq.emplace(-0, 0);
    visited[0] = 0;
    while (!pq.empty()) {
        dist = -pq.top().first;
        a = pq.top().second;
        pq.pop();
        
        
        // cout << 'n' << a+1 << ' ' << dist << '\n';
        if (visited[a] < dist) {
            continue;
        }
        
        for (auto edge : edges[a]) {
            d = edge.first;
            b = edge.second;
            nd = (dist)%M > d ? (dist/M + 1)*M+d+1 :  (dist/M)*M+d+1;
            
            if (visited[b] > nd) {
                // cout << b+1 <<  ' ' << nd << '\n';
                visited[b] = nd;
                pq.emplace(-nd, b);
            }
        }
    }
    
    cout << visited[N-1];
    
    return 0;
}