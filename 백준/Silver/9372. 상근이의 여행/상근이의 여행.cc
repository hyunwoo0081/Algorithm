#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int T, N, M, a, b;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        while (M--) {
            cin >> a >> b;
        }
        cout << N-1 << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}