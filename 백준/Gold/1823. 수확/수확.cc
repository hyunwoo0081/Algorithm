#include <iostream>

using namespace std;
typedef long long ll;

ll dp[2000][2000] = {0};
int arr[2000];

ll getMax(int s, int e, int k) {
    if (dp[s][e] != 0) return dp[s][e];
    if (s == e) return dp[s][e] = arr[s]*k;

    return dp[s][e] = max(getMax(s+1, e, k+1) + arr[s]*k, getMax(s, e-1, k+1) + arr[e]*k);
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << getMax(0, N-1, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}