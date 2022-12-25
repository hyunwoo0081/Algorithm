#include <iostream>
#define SIZE 1024

using namespace std;

int prefix[SIZE][SIZE];

int getDp(int x, int y) {
    return x >= 0 && y >= 0 ? prefix[y][x] : 0;
}

void solution() {
    int N, M, K, x1, y1, x2, y2;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> prefix[y][x];
            prefix[y][x] += getDp(x, y-1) + getDp(x-1, y) - getDp(x-1, y-1);
        }
    }

    cin >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        cout << getDp(y2, x2) - getDp(y1-1, x2) - getDp(y2, x1-1) + getDp(y1-1, x1-1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}