#include <iostream>

using namespace std;

void solution() {
    int N;
    cin >> N;
    while (N > 0) {
        cout << N*(N+1)/2 << '\n';
        cin >> N;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}