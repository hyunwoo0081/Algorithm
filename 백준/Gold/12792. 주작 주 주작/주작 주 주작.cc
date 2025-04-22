#include <iostream>

using namespace std;

void solution() {
    int N, a;
    bool cant = false;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cant |= (a-1 == i);
    }

    cout << (cant ? -1 : 1000003);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}