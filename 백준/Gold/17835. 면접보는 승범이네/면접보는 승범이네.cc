#include <iostream>
#include <queue>
#define SIZE 100'000
#define INF 9876543219876543
#define ll long long

using namespace std;

priority_queue<pair<ll, ll>> pq;
vector<pair<ll, ll>> edges[SIZE];
ll visited[SIZE];

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    ll N, M, K, from, to, dist, d;
    
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        visited[i] = INF;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> from >> to >> dist;
        from--, to--;
        edges[to].emplace_back(dist, from);
    }
    
    for (int i = 0; i < K; i++) {
        cin >> to;
        to--;
        
        visited[to] = 0;
        pq.emplace(0, to);
    }
    
    ll maxLen = 0;
    ll maxN = 1;
    while (!pq.empty()) {
        from = pq.top().second;
        dist = -pq.top().first;
        pq.pop();
        
        if (dist > visited[from]) {
            continue;
        }
        
        maxLen = dist;
        maxN = from+1;
        
        for (auto edge : edges[from]) {
            d = dist + edge.first;
            to = edge.second;
            
            if (visited[to] > d) {
                pq.emplace(-d, to);
                visited[to] = d;
            }
        }
    }
    
    // int maxLen = 0;
    // int maxN = 1;
    // for (int i = 0; i < N; i++) {
    //     if (visited[i] > maxN) {
    //         maxN = i + 1;
    //         maxLen = visited[i];
    //     }
    // }
    
    cout << maxN << '\n' << maxLen;

    return 0;
}