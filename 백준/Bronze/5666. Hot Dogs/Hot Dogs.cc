#include <iostream>

using namespace std;

void solution() {
    int H, P;

    cout << fixed;
    cout.precision(2);

    while (cin >> H >> P) {
        cout << H/(double)P << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}