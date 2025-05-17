#include <iostream>
#define SIZE 100

using namespace std;

string maps[SIZE];

void solution() {
    int X, Y, cnt = 0;
    string s;

    cin >> Y >> X;
    for (int y = 0; y < Y; y++) {
        cin >> maps[y];
    }


    for (int y = 0; y < Y; y++) {
        cin >> s;
        for (int x = 0; x < X; x++) {
            cnt += maps[y][x] == s[x];
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}