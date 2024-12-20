#include <iostream>
#define MAX 3*3

using namespace std;

int arr[MAX][MAX];

void solution() {
    int T, N, x, y;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        for (int i = 0; i < N*N; i++) {
            for (int j = 0; j < N*N; j++) {
                cin >> arr[i][j];
            }
        }

        bool isCorrect = true;
        for (y = 0; y < N*N; y++) {
            for (int i = 0; i < N*N; i++) {
                isCorrect &= arr[y][i] > 0 && arr[y][i] <= N*N;
                for (int j = 0; j < N*N; j++)
                    isCorrect &= i == j || arr[y][i] != arr[y][j];
            }
        }

        for (x = 0; x < N*N; x++) {
            for (int i = 0; i < N*N; i++)
                for (int j = 0; j < N*N; j++)
                    isCorrect &= i == j || arr[i][x] != arr[j][x];
        }

        for (int i = 0; i < N*N; i++) {
            int sx = (i / N) * N;
            int sy = (i % N) * N;

            for (int j = 0; j < N*N; j++) {
                int nx = sx + j / N;
                int ny = sy + j % N;

                for (int k = 0; k < N*N; k++) {
                    int mx = sx + k / N;
                    int my = sy + k % N;

                    isCorrect &= j == k || arr[ny][nx] != arr[my][mx];
                }
            }
        }

        cout << "Case #" << t << ": " << (isCorrect ? "Yes" : "No") << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}