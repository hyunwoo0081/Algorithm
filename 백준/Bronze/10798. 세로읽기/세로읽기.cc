#include <iostream>
#include <vector>

using namespace std;

string arr[5];

void solution() {
    int maxL = 0;

    for (auto &s: arr) {
        cin >> s;
        maxL = max(maxL, (int) s.length());
    }

    for (int i = 0; i < maxL; i++)
        for (auto &s:arr)
            if (i < s.length())
                cout << s[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}