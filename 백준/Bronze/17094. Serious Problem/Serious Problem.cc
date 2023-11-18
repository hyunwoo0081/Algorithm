#include <iostream>

using namespace std;

void solution() {
    int cnt2, cntE, n;
    string s;

    cnt2 = cntE = 0;

    cin >> n >> s;
    for (auto c : s) {
        if (c == '2')
            cnt2++;
        else
            cntE++;
    }

    if (cnt2 > cntE)
        cout << '2';
    else if (cnt2 == cntE)
        cout << "yee";
    else
        cout << 'e';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}