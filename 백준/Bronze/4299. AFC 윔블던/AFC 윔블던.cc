#include <iostream>

using namespace std;

void solution() {
    int A, B;

    cin >> A >> B;
    if ((A+B) % 2 != 0 || (A-B) % 2 != 0 || A < B)
        cout << -1;
    else
        cout << (A+B)/2 << ' ' << (A-B)/2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}