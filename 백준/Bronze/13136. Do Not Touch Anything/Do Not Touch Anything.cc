#include <iostream>

using namespace std;

void solution() {
    long long w, h, a;

    cin >> w >> h >> a;
    cout << (w/a + (w%a != 0)) * (h/a + (h%a != 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}