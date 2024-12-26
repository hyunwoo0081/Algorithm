#include <iostream>
#define SIZE 100

using namespace std;

bool maps[SIZE][SIZE];

void solution() {
    int X, Y;
    string s;

    cin >> Y >> X;
    while (X || Y) {
        for (int y = 0; y < Y; y++) {
            cin >> s;
            for (int x = 0; x < X; x++) {
                maps[y][x] = s[x] == '#';
            }
        }

        int count = 0;
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (!maps[y][x]) continue;

                bool isAlone = true;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        if (x + dx < 0 || x + dx >= X || y + dy < 0 || y + dy >= Y) continue;
                        if (maps[y + dy][x + dx]) {
                            isAlone = false;
                            break;
                        }
                    }
                    if (!isAlone) break;
                }

                count += isAlone;
            }
        }

        cout << count << '\n';

        cin >> Y >> X;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}