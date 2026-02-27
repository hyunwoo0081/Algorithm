#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define NODE_SIZE 100000
#define EDGE_SIZE 500000
#define INF 9876543219876543L
#define ll long long

using namespace std;

vector<ll> costs;
vector<pair<int, ll>> edges[NODE_SIZE];
priority_queue<pair<ll, int>> pq;
ll visited[NODE_SIZE];

void initVisited(int N) {
    for (int i = 0; i < N; i++) {
        visited[i] = INF;
    }
}

bool dijstra(int start, int end, ll thres, ll C, int N) {
    initVisited(N);
    
    pq.emplace(0, start);
    visited[start] = 0;
    
    while (!pq.empty()) {
        ll dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (visited[node] < dist) {
            continue;
        }
        // cout << dist << ' ' << node+1 << '\n';
        
        if (node == end) {
            break;
        }
        
        for (auto edge : edges[node]) {
            int next = edge.first;
            int d = edge.second;
            if (d <= thres && dist+d < visited[next]) {
                visited[next] = dist + d;
                pq.emplace(-visited[next], next);
            }
        }
    }
    
    while (!pq.empty()) {
        pq.pop();
    }
    
    return visited[end] <= C;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, A, B, from, to, cost;
    ll left, right, mid, C, result;
    
    cin >> N >> M >> A >> B >> C;
    A--, B--;
    for (int m = 0; m < M; m++) {
        cin >> from >> to >> cost;
        from--, to--;
        
        edges[from].emplace_back(to, cost);
        edges[to].emplace_back(from, cost);
        
        costs.push_back(cost);
    }
    
    
    sort(costs.begin(), costs.end());
    costs.erase(unique(costs.begin(), costs.end()), costs.end());
    
    // paramatric search
    left = 0;
    right = costs.size() - 1;
    result = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        
        // cout << costs[mid] << " >> \n";
        if (dijstra(A, B, costs[mid], C, N)) {
            result = costs[mid];
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << result;
    
    return 0;
}