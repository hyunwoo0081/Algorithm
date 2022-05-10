#include <iostream>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 100000000

using namespace std;

int dists[100][100];
int maxLength[100];
int unions[100];
int boss[100] = {0};

int findRoot(int x) {
    while (unions[x] != x)
        x = unions[x];
    return x;
}

void joinUnions(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a != b) {
        unions[b] = a;
    }
}

void solution() {
    int N, M, x, y;

    cin >> N >> M;
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            dists[y][x] = INF;
        }
        unions[y] = y;
    }
    while (M--) {
        cin >> x >> y;
        x--, y--;
        dists[x][y] = dists[y][x] = 1;
        joinUnions(x, y);
    }

    for (int i = 0; i < N; ++i) unions[i] = findRoot(i);
    for (int i = 0; i < N; ++i) unions[i] = -unions[i];
    int unionCount = 0;
    int tmp;
    for (int i = 0; i < N; ++i) {
        if (unions[i] <= 0) {
            tmp = unions[i];
            ++unionCount;
            for (int j = i; j < N; ++j) {
                if (unions[j] == tmp) unions[j] = unionCount;
            }
        }
    }


    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != k && j != k && i != j) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }
    }



    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x)
            maxLength[y] = max(maxLength[y], dists[y][x] >= INF ? 0 : dists[y][x]);

        int &bossName = boss[unions[y]-1];
        if(bossName == 0 || maxLength[bossName-1] > maxLength[y])
            bossName = y+1;
    }
    sort(boss, boss + unionCount);

    cout << unionCount << '\n';
    for (int i = 0; i < unionCount; ++i) {
        cout << boss[i] << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}