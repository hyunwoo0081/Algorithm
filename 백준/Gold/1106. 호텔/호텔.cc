#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

priority_queue<pair<int, int>> q;
vector<pair<int, int>> edges;
int dist[2000] = {0};

void solution() {
    int C, N, cost, customer, nCost, nCustomer;

    cin >> C >> N;
    while (N--) {
        cin >> cost >> customer;
        edges.emplace_back(cost, customer);
    }

    for (auto &d: dist)
        d = INF;

    q.emplace(0, 0);
    dist[0] = 0;
    while (!q.empty()) {
        cost = -q.top().first;
        customer = q.top().second;
        q.pop();

        if (cost > dist[customer])
            continue;
        if (customer >= C) {
            cout << cost;
            return;
        }

        for (auto edge: edges) {
            nCost = cost + edge.first;
            nCustomer = customer + edge.second;

            if (nCost < dist[nCustomer]) {
                q.emplace(-nCost, nCustomer);
                dist[nCustomer] = nCost;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}