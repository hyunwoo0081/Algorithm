#include <iostream>

using namespace std;

int daysInMonth(int m, int y) {
    if (m == 2) {
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else {
        return 31;
    }
}

void solution() {
    int y, m, d;

    cin >> d >> m >> y;
    while (m || d || y) {
        if (m > 0 && m <= 12 && d > 0 && d <= daysInMonth(m, y)) {
            cout << "Valid\n";
        } else {
            cout << "Invalid\n";
        }

        cin >> d >> m >> y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}