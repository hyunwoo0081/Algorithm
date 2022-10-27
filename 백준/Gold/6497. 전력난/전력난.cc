#include <iostream>
#include <queue>
#define SIZE 200000

using namespace std;
typedef long long ll;

priority_queue<pair<ll, ll>> q;
vector<pair<ll, ll>> edges[SIZE];
bool visited[SIZE] = {false};

void solution() {
    ll N, M, x, y, z, minLength, sum;

    cin >> N >> M;
    while (N != 0 || M != 0) {
        sum = 0;

        while(!q.empty()) q.pop();
        for (int i = 0; i < SIZE; i++) {
            visited[i] = false;
            edges[i].clear();
        }
        
        while (M--) {
            cin >> x >> y >> z;
            sum += z;
            edges[x].emplace_back(y, z);
            edges[y].emplace_back(x, z);
        }

        visited[0] = true;
        for (auto e: edges[0])
            q.emplace(-e.second, e.first);

        N--;
        minLength = 0;
        while (N != 0) {
            x = q.top().second;
            z = -q.top().first;
            q.pop();

            if (visited[x])
                continue;

            N--;
            minLength += z;
            visited[x] = true;
            for (auto e: edges[x])
                q.emplace(-e.second, e.first);
        }

        cout << sum - minLength << '\n';
        cin >> N >> M;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
