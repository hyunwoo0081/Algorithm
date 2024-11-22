#include <iostream>
#include <map>
#define SIZE 50

using namespace std;

char maps[SIZE][SIZE];

void solution() {
    int Y, X;
    string s;

    cin >> Y >> X;
    for (int y = 0; y < Y; y++) {
        cin >> s;
        for (int x = 0; x < X; x++)
            maps[y][x] = s[x];
    }

    int result = 0;
    for (char m = 'A'; m <= 'Z'; m++) {
        for (char o = 'A'; o <= 'Z'; o++) {
            if (m == o || m == 'M' || o == 'O') continue;
            int cnt = 0;

            for (int y = 0; y < Y; y++) {
                for (int x = 0; x < X; x++) {
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0)
                                continue;

                            int nx = x + 2*dx;
                            int ny = y + 2*dy;
                            if (nx < 0 || X <= nx || ny < 0 || Y <= ny)
                                continue;

                            cnt += maps[y][x] == m && maps[y+dy][x+dx] == o && maps[y+2*dy][x+2*dx] == o;
                        }
                }
            }

            result = max(result, cnt);
        }
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}