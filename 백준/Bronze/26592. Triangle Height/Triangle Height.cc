#include <iostream>

using namespace std;

void solution() {
    int T;
    double A, W;

    cin>> T;
    while (T--) {
        cin >> A >> W;

        cout.precision(2);
        cout << "The height of the triangle is "  << fixed << A/W*2. << " units\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}