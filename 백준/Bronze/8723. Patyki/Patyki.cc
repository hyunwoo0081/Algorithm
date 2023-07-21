#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void solution() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    if (a == b && b == c)
        cout << 2;
    else if (a*a + b*b == c*c)
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}