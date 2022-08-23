#include <iostream>

using namespace std;

void solution() {
    bool arr[31] = {false};
    int a;

    for (int i = 0; i < 28; i++) {
        cin >> a;
        arr[a] = true;
    }

    for (int i = 1; i <= 30; i++)
        if (!arr[i]) cout << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}