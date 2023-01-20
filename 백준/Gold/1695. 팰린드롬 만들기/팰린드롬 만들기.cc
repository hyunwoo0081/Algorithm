#include <iostream>
#include <unordered_map>
#define SIZE 5000

using namespace std;

int dp[SIZE][SIZE];
int inputs[SIZE];

int getMinCount(int start, int end) {
    if (dp[start][end] != 0)
        return dp[start][end] - 1;
    if (start >= end)
        return 0;

    if (inputs[start] == inputs[end]) {
        dp[start][end] = 1 + getMinCount(start+1, end-1);
        return dp[start][end] - 1;
    }

    dp[start][end] = 2 + min(getMinCount(start+1, end), getMinCount(start, end-1));
    return dp[start][end] - 1;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> inputs[i];

    cout << getMinCount(0, N-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}