#include <iostream>

using namespace std;

void solution() {
    int result, d;
    char cmd;

    cin >> d >> cmd;
    result = d;
    while (cmd != '=') {
        cin >> d;
        switch (cmd) {
            case '+': result += d; break;
            case '-': result -= d; break;
            case '*': result *= d; break;
            case '/': result /= d; break;
        }
        cin >> cmd;
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}