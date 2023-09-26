#include <iostream>

using namespace std;

void solution() {
    int N, a, count, result;

    count = result = 0;
    cin >> N;
    while (N--) {
        cin >> a;
        count = a == 0 ? 0 : count + 1;
        result = max(result, count);
    }
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}