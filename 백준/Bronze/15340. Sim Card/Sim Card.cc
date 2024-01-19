#include <iostream>

using namespace std;

void solution() {
    int c, d, minR;

    cin >> c >> d;
    while (c || d) {
        minR = 30*c + 40*d;
        minR = min(minR, 35*c + 30*d);
        minR = min(minR, 40*c + 20*d);

        cout << minR << '\n';

        cin >> c >> d;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}