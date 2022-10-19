#include <iostream>
#define SIZE 5'000'001

using namespace std;
typedef long long ll;

int minDiv[SIZE] = {0};

void solution() {
    int N, k;
    cin >> N;

    for (int i = 2; i*i < SIZE; i++) {
        if (minDiv[i] != 0)
            continue;

        for (int j = i; i*j < SIZE; j++)
            if (minDiv[i*j] == 0)
                minDiv[i*j] = i;
    }

    while (N--) {
        cin >> k;

        while (minDiv[k] != 0) {
            cout << minDiv[k] << ' ';
            k /= minDiv[k];
        }
        cout << k << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
