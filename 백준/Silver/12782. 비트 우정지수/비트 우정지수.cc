#include <iostream>
#include <algorithm>

using namespace std;

int a[10], b[10];

void solution() {
    int T, zero1, one0;
    string A, B;

    cin >> T;
    while (T--) {
        cin >> A >> B;
        zero1 = one0 = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (A[i] == '0') zero1++;
                else one0++;
            }
        }

        cout << min(zero1, one0) + abs(zero1 - one0) << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}