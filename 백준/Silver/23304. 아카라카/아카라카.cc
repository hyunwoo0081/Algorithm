#include <iostream>

using namespace std;

void solution() {
    int l, i, j;
    string s;
    bool isAkaraka = true;

    cin >> s;
    l = s.length();

    while (l > 1) {
        i = 0, j = l-1;
        while (i < j && s[i] == s[j])
            i++, j--;
        if (i < j) isAkaraka = false;

        l /= 2;
    }

    cout << (isAkaraka ? "AKARAKA" : "IPSELENTI");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}