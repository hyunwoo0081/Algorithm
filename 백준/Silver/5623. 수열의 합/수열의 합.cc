#include <iostream>
#define SIZE 1000
#define ll long long

using namespace std;

ll sumMap[SIZE][SIZE] = {0};

void solution() {
    ll N, x, y, s, i;

    cin >> N;
    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            cin >> sumMap[y][x];

    if (N == 2) {
        x = sumMap[0][1] / 2;
        cout << x << ' ' << x;
        return;
    }

    for (i = 0; i < N-2; i++) {
        s = (sumMap[i][i+1] + sumMap[i][i+2] - sumMap[i+1][i+2]) / 2;
        cout << s << ' ';
    }

    // 나머지 두개
    s = (sumMap[i][i-1] + sumMap[i][i+1] - sumMap[i-1][i+1]) / 2;
    cout << s << ' ';
    i++;

    s = (sumMap[i][i-1] + sumMap[i][i-2] - sumMap[i-1][i-2]) / 2;
    cout << s;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}