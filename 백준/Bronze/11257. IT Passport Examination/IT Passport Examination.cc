#include <iostream>

using namespace std;

void solution() {
    const int weights[3] = {35, 30, 30};
    const int limit = 55;
    int T, arr[3];
    string s;


    cin >> T;
    while (T--) {
        cin >> s;
        for (auto &i : arr)
            cin >> i;

        bool isFail = false;
        for (int i = 0; i < 3; i++) {
            if (arr[i] < weights[i]*3/10.) {
                isFail = true;
                break;
            }
        }

        int sums = 0;
        for (int i : arr)
            sums += i;

        if (sums < limit)
            isFail = true;

        cout << s << ' ' << sums << ' ';
        cout << (isFail ? "FAIL" : "PASS") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}