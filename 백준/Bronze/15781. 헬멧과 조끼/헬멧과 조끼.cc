#include <iostream>

using namespace std;

void solution() {
    int maxN, t1, t2, a, result;

    cin >> t1 >> t2;
    maxN = -1;
    while (t1--) {
        cin >> a;
        maxN = max(maxN, a);
    }
    result = maxN;

    maxN = -1;
    while (t2--) {
        cin >> a;
        maxN = max(maxN, a);
    }
    result += maxN;

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}