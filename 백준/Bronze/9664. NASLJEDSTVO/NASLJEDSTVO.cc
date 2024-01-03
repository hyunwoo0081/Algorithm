#include <iostream>

using namespace std;

void solution() {
    int N, O;

    cin >> N >> O;
    N--;
    cout << O + O / N - (O % N == 0) << ' ' << O + O / N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}