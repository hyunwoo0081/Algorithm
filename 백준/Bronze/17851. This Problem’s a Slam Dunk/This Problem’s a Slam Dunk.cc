#include <algorithm>
#include <iostream>
#define SIZE 5

using namespace std;

void solution() {
    int a[SIZE], b[SIZE];

    for (auto &i : a) {
        cin >> i;
    }

    for (auto &i : b) {
        cin >> i;
    }

    sort(a, a + SIZE);
    sort(b, b + SIZE);

    int count = 0;
    for (int j = 0; j < SIZE; ++j) {
        count += a[j] > b[j];
    }
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}