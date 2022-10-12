#include <iostream>

using namespace std;

void solution() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 31; i++)
            if ((N & (1 << i)) != 0)
                cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
