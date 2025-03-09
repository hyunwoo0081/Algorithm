#include <iostream>

using namespace std;

void solution() {
    int n;

    cin >> n;
    n--;
    n = n % 8;
    n = n < 4 ? n : 8 - n;
    cout << n + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}