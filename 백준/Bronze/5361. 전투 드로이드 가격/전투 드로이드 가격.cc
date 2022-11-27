#include <iostream>
#include <iomanip>

using namespace std;

void solution() {
    double prices[] = {350.34, 230.90, 190.55, 125.30, 180.90};
    double sumP;
    int T, count;

    cin >> T;
    while (T--) {
        sumP = 0;
        for (auto p : prices) {
            cin >> count;
            sumP += p * count;
        }
        cout << fixed;
        cout.precision(2);
        cout << '$' << sumP << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}