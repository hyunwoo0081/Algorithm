#include <iostream>
#include <algorithm>

using namespace std;

string dp[101][101];

string addString(string &a, string &b) {
    bool carry = false;
    int ai, bi, num;
    string s;

    ai = a.length()-1;
    bi = b.length()-1;
    while (ai >= 0 && bi >= 0) {
        num = a[ai]-'0' + b[bi]-'0' + carry;
        carry = num >= 10;
        num %= 10;
        s.push_back(num+'0');
        ai--, bi--;
    }

    while (ai >= 0) {
        num = a[ai]-'0' + carry;
        carry = num >= 10;
        num %= 10;
        s.push_back(num+'0');
        ai--;
    }

    while (bi >= 0) {
        num = b[bi]-'0' + carry;
        carry = num >= 10;
        num %= 10;
        s.push_back(num+'0');
        bi--;
    }

    if (carry)
        s.push_back('1');

    reverse(s.begin(), s.end());
    return s;
}

string& com(int n, int m) {
    if (m > n/2)
        m = n-m;
    if (m == 0 || n == 1)
        return dp[n][m] = "1";
    if (!dp[n][m].empty())
        return dp[n][m];

    return dp[n][m] = addString(com(n-1, m-1), com(n-1, m));
}

void solution() {
    int a, b;
    cin >> a >> b;
    cout << com(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}