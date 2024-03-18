#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int a, b, x, y;

    cin >> a >> b >> x >> y;
    cout << min(abs(b-a), min(abs(a-x)+abs(b-y), abs(b-x)+abs(a-y)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}