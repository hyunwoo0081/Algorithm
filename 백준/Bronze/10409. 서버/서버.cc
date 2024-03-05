#include <iostream>

using namespace std;

void solution() {
    int N, T, sum = 0, cnt = 0, a;

    cin >> N >> T;
    while (N-- && sum < T) {
        cin >> a;
        sum += a;
        cnt += sum <= T;
    }

    cout << cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}