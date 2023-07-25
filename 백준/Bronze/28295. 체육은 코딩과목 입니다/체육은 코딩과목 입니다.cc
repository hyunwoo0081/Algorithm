#include <iostream>

using namespace std;

char map[] = {'N', 'E', 'S', 'W'};

void solution() {
    int cmd, dir = 0;

    for (int i = 0; i < 10; i++) {
        cin >> cmd;
        dir = (dir + cmd) % 4;
    }

    cout << map[dir];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}