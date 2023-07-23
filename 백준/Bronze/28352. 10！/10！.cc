#include <iostream>

using namespace std;

void solution() {
    int x, result = 6;
    cin >> x;

    for (int i = 11; i <= x; i++)
        result *= i;
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}