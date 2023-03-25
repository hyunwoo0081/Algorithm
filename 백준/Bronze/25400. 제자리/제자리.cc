#include <iostream>

using namespace std;

void solution() {
    int N, a, count, result;

    count = 1;
    result = 0;

    cin >> N;
    while (N--) {
        cin >> a;
        result += a != count;
        count += a == count;
    }

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}