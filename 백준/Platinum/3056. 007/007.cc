#include <iostream>

using namespace std;

double dp[1<<20] = {1};
double inputs[20][20];

double getMaxMul(int N, int index, int selected) {
    if (dp[selected] >= 0)
        return dp[selected];

    double &cache = dp[selected];
    for (int i = 0; i < N; i++)
        if (selected & (1<<i))
            cache = max(cache, getMaxMul(N, index-1, selected ^ (1<<i)) * inputs[index][i]);

    return cache;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputs[i][j];
            inputs[i][j] /= 100;
        }
    }

    for (int i = 1; i < (1<<N); i++)
        dp[i] = -1;

    cout.precision(6);
    cout << fixed;
    cout << getMaxMul(N, N-1, (1<<N)-1) * 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}