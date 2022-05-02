#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int failure[1000000];

void solution() {
    int L;
    string s;
    cin >> L >> s;

    int j = 0;
    for (int i = 1; i < L; ++i) {
        while (j > 0 && s[i] != s[j])
            j = failure[j-1];

        if (s[i] == s[j])
            failure[i] = ++j;
    }

    cout << L-failure[L-1];
}

int main() {
    fastIO();
    solution();

    return 0;
}