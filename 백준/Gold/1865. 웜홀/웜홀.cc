#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<pair<pair<int, int>, int>> edges;
int dist[500];

void solution() {
    int TC, N, M, W, S, E, T;

    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        for (int i = 0; i < N; ++i)
            dist[i] = 1000000000;
        edges.clear();

        while (M--) {
            cin >> S >> E >> T;
            S--, E--;
            edges.emplace_back(make_pair(S, E), T);
            edges.emplace_back(make_pair(E, S), T);
        }
        while (W--) {
            cin >> S >> E >> T;
            S--, E--;
            edges.emplace_back(make_pair(S, E), -T);
        }

        int count = 0;
        bool hasNegativeLoop = false;
        while (count < N) {
            for (auto edge: edges) {
                S = edge.first.first;
                E = edge.first.second;
                T = edge.second;
                if (dist[S]+T < dist[E]){
                    dist[E] = dist[S]+T;
                    if (count == N-1)
                        hasNegativeLoop = true;
                }
            }
            count++;
        }
        cout << (hasNegativeLoop ? "YES\n" : "NO\n");
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}