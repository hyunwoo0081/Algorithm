#include <iostream>
#define LIM_X 1000
#define LIM_Y 100

using namespace std;

char maps[LIM_Y][LIM_X];
void solution() {
    int Y, X, x, y, dx, dy;
    string s;

    cin >> Y >> X;
    for (y = 0; y < Y; y++) {
        cin >> s;
        for (x = 0;x < X; x++) {
            maps[y][x] = s[x];
        }
    }

    // vertical check
    bool isPossible = false;
    for (y = 1; y < Y-1; y++) {
        isPossible = true;
        for (dx = -1-(X+1)%2; dx <= 1; dx++) {
            x = X/2 + dx;
            isPossible &= maps[y][x] == 'X';
        }

        if (isPossible) {
            for (dx = -(X+1)%2; dx <= 0; dx++) {
                x = X/2 + dx;
                maps[y][x] = 'Y';
            }
            x = X/2-1-(X+1)%2;
            maps[y][x] = 'W';
            x = X/2 + 1;
            maps[y][x] = 'W';

            break;
        }
    }

    if (isPossible == false) {
        // horizontal check
        for (y = 1; y < Y-2; y++) {
            isPossible = true;
            for (dy = 0; dy < 3; dy++) {
                for (dx = -((X+1)%2); dx <= 0; dx++) {
                    x = X/2 + dx;
                    isPossible &= maps[y+dy][x] == 'X';
                }
            }

            if (isPossible) {
                for (dy = 0; dy < 3; dy++) {
                    for (dx = -((X+1)%2); dx <= 0; dx++) {
                        x = X/2 + dx;
                        maps[y+dy][x] = dy == 1 ? 'Y' : 'W';
                    }
                }
                break;
            }
        }
    }

    if (!isPossible) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (y = 0; y < Y; y++) {
            for (x = 0; x < X; x++) {
                cout << (maps[y][x] == 'X' ? 'B' : maps[y][x]);
            }
            cout << '\n';
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}