#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100000
#define ll long long
#define INF 987654321987654L

using namespace std;

bool canVisit[SIZE] = {false};
vector<pair<int, int>> edges[SIZE];
ll visited[SIZE] = {};
priority_queue<pair<ll, int>> pq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, a, b, t;
    ll time, ntime;
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a;
        canVisit[i] = a == 0;
        visited[i] = INF;
    }
    canVisit[N-1] = true;
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        if (!canVisit[a] || !canVisit[b]) {
            continue;
        }
        
        edges[a].emplace_back(t, b);
        edges[b].emplace_back(t, a);
    }
    
    pq.emplace(-0, 0);
    visited[0] = 0;
    while (!pq.empty()) {
        time = -pq.top().first;
        a = pq.top().second;
        pq.pop();
        
        if (visited[a] < time) {
            continue;
        }
        
        for (auto edge : edges[a]) {
            ntime = time + edge.first;
            b = edge.second;
            
            if (visited[b] > ntime) {
                pq.emplace(-ntime, b);
                visited[b] = ntime;
            }
        }
    }
    
    if (visited[N-1] == INF) {
        cout << -1;
    }
    else {
        cout << visited[N-1];
    }

    return 0;
}