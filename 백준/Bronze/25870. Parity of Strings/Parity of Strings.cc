#include <iostream>

using namespace std;

int cnts[26] = {0};

void solution() {
    string s;
    bool isOdd = false, isEven = false;

    cin >> s;
    for (char c : s) {
        cnts[c-'a']++;
    }

    for (auto a : cnts) {
        if (a == 0) continue;
        
        isOdd |= (a % 2 == 1);
        isEven |= (a % 2 == 0);
    }

    if (isOdd && isEven)
        cout << 2;
    else if (isOdd)
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}