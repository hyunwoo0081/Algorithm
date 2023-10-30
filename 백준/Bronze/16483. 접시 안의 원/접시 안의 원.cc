#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int T;
    cin >> T;
    cout << lround(T*T / 4.);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}