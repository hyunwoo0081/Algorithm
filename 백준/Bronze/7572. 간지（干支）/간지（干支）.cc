#include <iostream>

using namespace std;

void solution() {
    int N;

    cin >> N;
    N += 56;
    cout << (char) ('A' + N%12) << N%10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}