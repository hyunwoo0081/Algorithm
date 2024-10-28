#include <iostream>
#define SIZE 500

using namespace std;


string Spotty[SIZE], Plain[SIZE];
void solution() {
    int N, M, n, i, j, k, s, p, cnt;
    bool isSame;

    cin >> N >> M;
    for (n = 0; n < N; n++)
        cin >> Spotty[n];
    for (n = 0; n < N; n++)
        cin >> Plain[n];

    cnt = 0;
    for (i = 0; i < M-2; i++)
        for (j = i+1; j < M-1; j++)
            for (k = j+1; k < M; k++) {
                isSame = false;

                for (s = 0; s < N && !isSame; s++)
                    for (p = 0; p < N && !isSame; p++) {
                        isSame |= (Spotty[s][i] == Plain[p][i] && Spotty[s][j] == Plain[p][j] && Spotty[s][k] == Plain[p][k]);
                    }

                cnt += !isSame;
            }

    cout << cnt;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}