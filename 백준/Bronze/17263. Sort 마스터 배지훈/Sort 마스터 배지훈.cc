#include <iostream>

using namespace std;

void solution() {
    int N, a, maxN = 0;
    cin >> N;
    while (N--) {
        cin >> a;
        maxN = max(maxN, a);
    }
    cout << maxN;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}