#include <iostream>

using namespace std;

void solution() {
    int n, m, result = 0;

    cin >> n;
    while (n--) {
        cin >> m;
        result = (result + m) % 3;
    }

    cout << (result == 0 ? "yes" : "no") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}