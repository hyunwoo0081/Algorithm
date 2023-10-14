#include <iostream>

using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isMoreMonth(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
int getDay(int y, int m) {
    if (m == 2)
        return days[m-1] + isMoreMonth(y);
    return days[m-1];
}

void solution() {
    int sy, sm, sd, ey, em, ed, result = 0;

    cin >> sy >> sm >> sd;
    cin >> ey >> em >> ed;

    if (ey > sy + 1000 || ey == sy + 1000 && (em > sm || em == sm && ed >= sd)) {
        cout << "gg";
        return;
    }

    // sd = 1
    result = -sd + 1;
    sd = 1;

    // month / year
    while (ey != sy || em != sm) {
        result += getDay(sy, sm);

        sm += 1;
        if (sm > 12) {
            sm = 1;
            sy += 1;
        }
    }

    // day
    result += ed - sd;
    ed = sd;
    cout << "D-" << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}