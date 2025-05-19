#include <algorithm>
#include <iostream>
#define SIZE 100

using namespace std;

string maps[SIZE];

void solution() {
    string a, b, result;
    bool ai, bi, ci;
    int T;

    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ci = false;
    T = max(a.length(), b.length());
    for (int i = 0; i < T; i++) {
        ai = i < a.length() ? a[i] == '1' : false;
        bi = i < b.length() ? b[i] == '1' : false;

        result += ai && (!bi && !ci || bi && ci) || !ai && (!bi && ci || bi && !ci) ? '1' : '0';
        ci = bi && ci || ai && (!bi && ci || bi && !ci);
    }

    if (ci)
        result += '1';

    reverse(result.begin(), result.end());
    while (result.length() > 1 && result[0] == '0')
        result.erase(result.begin());

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}