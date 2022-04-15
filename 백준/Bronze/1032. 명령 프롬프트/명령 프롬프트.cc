#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int N;
    string cmd;
    string c;

    cin >> N >> cmd;
    N--;
    while (N--) {
        cin >> c;
        for (auto i = 0; i < cmd.size(); ++i) {
            if (cmd[i] != c[i]) cmd[i] = '?';
        }
    }

    cout << cmd;
}

int main() {
    fastIO();
    solution();

    return 0;
}