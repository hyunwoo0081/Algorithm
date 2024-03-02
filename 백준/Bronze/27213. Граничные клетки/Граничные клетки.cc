#include <iostream>

using namespace std;

void solution() {
    int X, Y;

    cin >> X >> Y;
    if (Y == 1 || X == 1)
        cout << X*Y;
    else
        cout << 2 * (X + Y - 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}