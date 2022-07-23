#include <iostream>

using namespace std;

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (j%2 ? ' ' : '*');
        cout << '\n';
        for (int j = 0; j < N; j++)
            cout << (j%2 ? '*' : ' ');
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}