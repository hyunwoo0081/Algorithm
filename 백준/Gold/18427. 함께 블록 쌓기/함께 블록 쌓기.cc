#include <iostream>
#include <vector>
#include <sstream>
#define MOD 10'007

using namespace std;

int dp[10][1001];
int sums[1001] = {1};

vector<int> split(string &s) {
    vector<int> result;
    istringstream ss(s);
    string num;

    while (getline(ss, num, ' '))
        result.push_back(stoi(num));

    return result;
}

void solution() {
    int N, M, H, count;
    string s;

    cin >> N >> M >> H;
    cin.ignore();
    while (N--) {
        count = 0;
        getline(cin, s);
        for (auto v : split(s)) {
            for (int i = H; i >= v; i--)
                dp[count][i] = sums[i-v];
            for (int i = 0; i < v; i++)
                dp[count][i] = 0;
            count++;
        }

        for (int i = 0; i < count; i++)
            for (int j = 1; j <= H; j++)
                sums[j] = (sums[j] + dp[i][j]) % MOD;
    }

    cout << sums[H];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}