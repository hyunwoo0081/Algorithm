#include <iostream>

using namespace std;

void solution() {
    int h, m;
    cin >> h >> m;
    cout << (h-9)*60 + m;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}