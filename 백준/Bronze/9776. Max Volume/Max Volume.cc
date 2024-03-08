#include <iostream>
#define PI 3.141592

using namespace std;

void solution() {
    int T;
    char c;
    double r, h, maxV = 0;

    cin >> T;
    while (T--) {
        cin >> c;
        if (c == 'S') {
            cin >> r;
            maxV = max(maxV, 4 * PI * r * r * r / 3.);
        }
        else if (c == 'C') {
            cin >> r >> h;
            maxV = max(maxV, PI * r * r * h / 3.);
        }
        else if (c == 'L') {
            cin >> r >> h;
            maxV = max(maxV, PI * r * r * h);
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << maxV;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}