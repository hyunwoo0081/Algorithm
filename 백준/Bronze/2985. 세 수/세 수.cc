#include <iostream>

using namespace std;

void solution() {
    int a, b, c;

    cin >> a >> b >> c;
    if (a == b + c)
        cout << a << '=' << b << '+' << c;
    else if (a == b - c)
        cout << a << '=' << b << '-' << c;
    else if (a == b * c)
        cout << a << '=' << b << '*' << c;
    else if (c != 0 && a == b / c && b % c == 0)
        cout << a << '=' << b << '/' << c;
    else if (a + b == c)
        cout << a << '+' << b << '=' << c;
    else if (a - b == c)
        cout << a << '-' << b << '=' << c;
    else if (a * b == c)
        cout << a << '*' << b << '=' << c;
    else if (b != 0 && a / b == c && a % b == 0)
        cout << a << '/' << b << '=' << c;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}