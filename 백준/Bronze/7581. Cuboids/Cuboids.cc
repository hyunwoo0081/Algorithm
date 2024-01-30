#include <iostream>

using namespace std;

void solution() {
    long long arr[4], index, v;

    while (true) {
        index = -1;
        for (int i = 0; i < 4; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                index = index > -1 ? -2 : i;
                if (index == -2) break;
            }
        }

        if (index <= -1)
            break;

        v = 1;
        for (int i = 0; i < 3; i++)
            if (i != index) v *= arr[i];

        if (index != 3)
            v = arr[3]/v;

        for (int i = 0; i < 4; i++) {
            cout << (i == index ? v : arr[i]) << ' ';
        }
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}