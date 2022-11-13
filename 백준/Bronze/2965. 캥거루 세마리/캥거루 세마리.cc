#include <iostream>

using namespace std;

void solution() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(c-b, b-a) - 1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}