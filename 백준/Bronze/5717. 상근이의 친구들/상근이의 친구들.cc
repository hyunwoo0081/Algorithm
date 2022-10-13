#include <iostream>

using namespace std;

void solution() {
    int a, b;

    cin >> a >> b;
    while (a != 0 || b != 0) {
        cout << a+b << '\n';
        cin >> a >> b;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
