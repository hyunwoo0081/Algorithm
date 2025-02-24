#include <iostream>

using namespace std;

void solution() {
    int X, Y;

    cin >> X >> Y;
    for (int i = X; i <= Y; i += 60) {
        cout << "All positions change in year " << i << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}