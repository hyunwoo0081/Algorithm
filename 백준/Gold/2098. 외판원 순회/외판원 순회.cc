#include <iostream>
#define INF 100'000'000

using namespace std;

int dist[16][16];
int dp[16][1<<16] = {0};

int shortest(int node, int visited, int N) {
    if (visited == (1<<N)-1)
        return dist[node][0] ? dist[node][0] : INF;

    int& ret = dp[node][visited];
    if (ret > 0) return ret;
    ret = INF;

    for (int next = 0; next < N; next++) {
        if (visited & 1<<next || !dist[node][next]) continue;
        int d = dist[node][next] + shortest(next, visited|1<<next, N);
        ret = min(ret, d);
    }

    return ret;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    cout << shortest(0, 1, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}