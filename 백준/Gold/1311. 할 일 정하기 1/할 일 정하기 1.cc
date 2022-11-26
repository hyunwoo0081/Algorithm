#include <iostream>
#define INF 987654321

using namespace std;

int minCost[2<<20] = {0};
int map[20][20];

int getMinCost(int N, int visited, int depth) {
    int &cache = minCost[visited];
    if (cache != 0 || visited == 0)
        return cache;

    cache = INF;
    for (int i = 0; i < N; i++)
        if (visited & (1 << i))
            cache = min(cache, map[depth-1][i] + getMinCost(N, visited ^ (1 << i), depth-1));

    return cache;
}

void solution() {
    int N;

    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> map[y][x];

    cout << getMinCost(N, (1<<N)-1, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}