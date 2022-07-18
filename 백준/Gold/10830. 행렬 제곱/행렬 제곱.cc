#include <iostream>

using namespace std;

int result[5][5];

void mulMatrix(int r[5][5], int b[5][5], int N) {
    int a[5][5];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = r[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            r[i][j] = 0;
            for (int k = 0; k < N; k++)
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % 1000;
        }
    }
}

void powMatrix(int r[5][5], int N, long long p) {
    if (p <= 1) return;

    int matrix[5][5], t[5][5];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = t[i][j] = r[i][j];

    if (p % 2) {
        mulMatrix(matrix, t, N);
        powMatrix(matrix, N, p/2);
        mulMatrix(r, matrix, N);
    }
    else {
        mulMatrix(r, matrix, N);
        powMatrix(r, N, p/2);
    }
}

void solution() {
    int N;
    long long B;

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> result[i][j];
            result[i][j] %= 1000;
        }
    }

    powMatrix(result, N, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}