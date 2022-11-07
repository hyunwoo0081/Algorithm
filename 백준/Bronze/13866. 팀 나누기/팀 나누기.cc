#include <iostream>

using namespace std;

void solution() {
    int arr[4];
    int f, sum = 0;

    for (auto &a: arr) {
        cin >> a;
        sum += a;
    }

    int minAbs = 987654321;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                f = abs(sum - 2*(arr[i]+arr[j]));
                minAbs = min(minAbs, f);
            }
        }
    }

    cout << minAbs;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
