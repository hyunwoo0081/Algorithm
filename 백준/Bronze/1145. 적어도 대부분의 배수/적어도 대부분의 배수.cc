#include <iostream>

using namespace std;

void solution() {
    int arr[5];
    int result = 0, cnt;
    bool isMul = false;

    for (auto &a : arr)
        cin >> a;

    while (!isMul) {
        result++;

        cnt = 0;
        for (auto a : arr)
            cnt += a <= result && result % a == 0;

        if (cnt >= 3) isMul = true;
    }

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}