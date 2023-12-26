#include <iostream>

using namespace std;

void solution() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a == 8 || a == 9) && b == c && (d == 8 || d == 9))
        cout << "ignore";
    else
        cout << "answer";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}