#include <iostream>

using namespace std;

void solution() {
    long long M, K;

    cin >> M >> K;
    cout << (M % K ? "No" : "Yes");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}