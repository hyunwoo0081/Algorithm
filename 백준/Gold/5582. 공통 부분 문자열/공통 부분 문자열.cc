#include <iostream>
#define SIZE 4000

using namespace std;

int dp[SIZE][SIZE];

void solution() {
    string s1, s2;
    int result = 0;

    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = i > 0 && j > 0 ? dp[i-1][j-1] + 1 : 1;
                result = max(result, dp[i][j]);
            }
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}