#include <iostream>

using namespace std;

void solution() {
    int a, sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> a;
        sum += a;
    }

    cout << sum/2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}