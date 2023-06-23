#include <iostream>

using namespace std;

void solution() {
    int d, h, m;

    cin >> d >> h >> m;
    cout << max(-1, ((d-11)*24+(h-11))*60+m-11);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}