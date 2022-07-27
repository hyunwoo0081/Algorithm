#include <iostream>
#define SIZE 2500

using namespace std;

bool isPel[SIZE][SIZE] = {false};
int dp[SIZE];

void makeCounts(string &s) {
    int N = s.length();
    int i, j;

    for (int k = 0; k < N; k++) {
        i = j = k;
        while (0 <= i && j < N && s[i] == s[j])
            isPel[i--][j++] = true;

        i = k, j = k+1;
        while (0 <= i && j < N && s[i] == s[j])
            isPel[i--][j++] = true;
    }
}

void solution() {
    string s;

    cin >> s;
    makeCounts(s);

    for (int i = 0; i < s.length(); i++) {
        dp[i] = i+1;
        for (int j = 0; j <= i; j++) {
            if (isPel[j][i])
                dp[i] = min(dp[i], j==0 ? 1 : 1+dp[j-1]);
        }
    }

    cout << dp[s.length()-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}