#include <iostream>

using namespace std;

int map[] = {4, 2, 3, 3, 3, 3, 3, 3, 3, 3};

void solution() {
    int N, result;

    cin >> N;
    while (N > 0) {
        result = 1;
        while (N > 0) {
            result += map[N%10] + 1;
            N /= 10;
        }
        cout << result << '\n';
        cin >> N;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}