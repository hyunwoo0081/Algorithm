#include <iostream>
#define SIZE 50

using namespace std;

bool pos[SIZE] = {false};

void solution() {
    int M, x, y, tmp;

    pos[0] = true;
    cin >> M;
    while (M--) {
        cin >> x >> y;
        x--, y--;

        tmp = pos[x];
        pos[x] = pos[y];
        pos[y] = tmp;
    }

    for (int i = 0; i < SIZE; i++)
        if (pos[i])
            cout << i+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}