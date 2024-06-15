#include <iostream>

using namespace std;

void solution() {
    int N, s, count;

    cin >> N;
    for (int i = 0; i < N; i++) {
        count = 0;
        for (int j = 0; j < 10; j++) {
            cin >> s;
            count += s == (j % 5 + 1);
        }

        if (count == 10)
            cout << i + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}