#include <iostream>

using namespace std;

void solution() {
    int arr[10];

    for (auto &a: arr)
        cin >> a;

    int sum = 0;
    for (auto a: arr)
        sum += a;
    cout << sum / 10 << '\n';

    int count = -1, result = -1, cnt;
    for (auto a: arr) {
        cnt = 0;
        for (auto b : arr)
            cnt += a == b;
        if (count < cnt) {
            count = cnt;
            result = a;
        }
    }
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}