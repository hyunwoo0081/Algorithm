#include <iostream>

using namespace std;

int T[15], P[15];

int getMaxProfit(int start, int N) {
    int profit = 0;

    for (int i = start; i < N; i++) {
        if (i+T[i] <= N)
            profit = max(profit, P[i] + getMaxProfit(i+T[i], N));
    }
    return profit;
}

void solution() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];

    cout << getMaxProfit(0, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}