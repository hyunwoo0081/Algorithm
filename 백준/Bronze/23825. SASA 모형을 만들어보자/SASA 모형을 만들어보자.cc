#include <iostream>

using namespace std;

void solution() {
    int N, M;

    cin >> N >> M;
    cout << min(N/2, M/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}