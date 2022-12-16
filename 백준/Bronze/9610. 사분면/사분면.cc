#include <iostream>

using namespace std;

void solution() {
    int n, x, y, q1, q2, q3, q4, axis;

    cin >> n;
    q1 = q2 = q3 = q4 = axis = 0;
    while (n--) {
        cin >> x >> y;
        if (x == 0 || y == 0)
            axis++;
        else if (x > 0) {
            if (y > 0) q1++;
            else q4++;
        }
        else {
            if (y > 0) q2++;
            else q3++;
        }
    }

    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << axis << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}