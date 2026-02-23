#include <iostream>
#define SIZE 101
#define INF 987654321

using namespace std;

int cnts[SIZE][SIZE];

int main() {
    int N, M, start, end, from, to;
    
    cin >> N >> start >> end >> M;
    for (int y = 0; y <= N; y++) {
        for (int x = 0; x <= N; x++) {
            cnts[y][x] = INF;
        }
        cnts[y][y] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        cnts[from][to] = cnts[to][from] = 1;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cnts[i][j] = min(cnts[i][j], cnts[i][k] + cnts[k][j]);
            }
        }
    }
    
    cout << (cnts[start][end] == INF ? -1 : cnts[start][end]);

    return 0;
}