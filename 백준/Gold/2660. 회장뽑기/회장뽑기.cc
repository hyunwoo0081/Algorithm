#include <iostream>
#define SIZE 50
#define INF 987654

using namespace std;

int floid[SIZE][SIZE];

void solution() {
    int n, a, b;

    cin >> n;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            floid[y][x] = (x==y ? 0 : INF);

    cin >> a >> b;
    while(a != -1 && b != -1) {
        a--, b--;
        floid[a][b] = floid[b][a] = 1;

        cin >> a >> b;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                floid[i][j] = min(floid[i][j], floid[i][k] + floid[k][j]);

    int minN = INF;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            floid[i][0] = max(floid[i][0], floid[i][j]);

        if (minN > floid[i][0]) {
            minN = floid[i][0];
            count = 1;
        }
        else if (minN == floid[i][0])
            count++;
    }
    cout << minN << ' ' << count << '\n';

    for (int i = 0; i < n; i++)
        if (floid[i][0] == minN)
            cout << i+1 << ' ';


}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}