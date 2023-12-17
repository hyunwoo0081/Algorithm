#include <iostream>

using namespace std;

void solution() {
    int T, A, B, C, cnt;

    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        cnt = 0;
        for (int a = 1; a <= A; a++)
            for (int b = 1; b <= B; b++)
                for (int c = 1; c <= C; c++)
                    cnt += a % b == b % c && b % c == c % a;
        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}