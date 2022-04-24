#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Robot {
    int x, y, dir;
};

int map[100][100] = {0};
vector<Robot> robots;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int getDir(char dir) {
    switch (dir) {
        case 'N': return 1;
        case 'W': return 2;
        case 'E': return 0;
        default: return 3;
    }
}

void solution() {
    int A, B, N, M, x, y, index, loop, dirI;
    char dir, cmd;
    bool isCrashed = false;

    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y >> dir;
        x--, y--;
        robots.push_back({x, y, getDir(dir)});
        map[x][y] = i;
    }

    while (M--) {
        cin >> index >> cmd >> loop;
        index--;

        if(isCrashed) break;

        if (cmd == 'L') {
            robots[index].dir = (robots[index].dir + loop) % 4;
        }
        else if (cmd == 'R') {
            robots[index].dir = (robots[index].dir + loop*3) % 4;
        }
        else if (cmd == 'F'){
            x = robots[index].x;
            y = robots[index].y;
            dirI = robots[index].dir;
            map[x][y] = 0;

            while (loop--) {
                x += dx[dirI];
                y += dy[dirI];

                if (0 > x || x >= A || 0 > y || y >= B) {
                    cout << "Robot " << (index+1) << " crashes into the wall";
                    isCrashed = true;
                    break;
                }
                else if (map[x][y] != 0) {
                    cout << "Robot " << (index+1) << " crashes into robot " << (map[x][y]);
                    isCrashed = true;
                    break;
                }

                robots[index].x = x;
                robots[index].y = y;
            }

            if(!isCrashed)
                map[x][y] = index+1;
        }
    }

    if (!isCrashed)
        cout << "OK";

    cout << endl;
}


int main() {
    fastIO();
    solution();

    return 0;
}