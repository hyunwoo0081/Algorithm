#include <iostream>

using namespace std;

void solution() {
    string s;
    int uc, pd, cmp;

    cin >> s;
    uc = pd = 0;
    for (auto c : s) {
        cmp = (c == 'U' || c == 'C');
        uc += cmp;
        pd += !cmp;
    }

    if (pd == 0)
        cout << "U";
    else if (uc > (pd+1)/2)
        cout << "UDP";
    else
        cout << "DP";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}