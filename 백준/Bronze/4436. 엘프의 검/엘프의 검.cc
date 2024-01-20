#include <iostream>

using namespace std;

bool isExist[10] = {false};

bool isAll() {
    for (auto i : isExist)
        if (!i) return false;
    return true;
}

void solution() {
    long long N, cnt, tmp;

    while (cin >> N) {
        for (auto &i : isExist)
            i = false;

        cnt = 0;
        while (!isAll()) {
            cnt++;

            tmp = N*cnt;
            while (tmp > 0) {
                isExist[tmp%10] = true;
                tmp /= 10;
            }
        }

        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}