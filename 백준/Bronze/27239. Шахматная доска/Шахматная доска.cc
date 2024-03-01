#include <iostream>

using namespace std;

void solution() {
    int N;

    cin >> N;
    N--;
    cout << (char)('a' + N % 8) << N / 8 + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}