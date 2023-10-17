#include <iostream>

using namespace std;

void solution() {
    int N, s, d, result;

    cin >> N;
    while (N > 0) {
        result = 1;
        while (N--) {
            cin >> s >> d;
            result = result * s - d;
        }
        cout << result << '\n';
        cin >> N;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}