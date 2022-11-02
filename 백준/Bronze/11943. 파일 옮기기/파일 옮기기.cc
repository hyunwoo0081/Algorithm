#include <iostream>

using namespace std;

void solution() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    cout << min(a+d, b+c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
