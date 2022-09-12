#include <iostream>
#include <queue>

using namespace std;

char map[102][102];
bool visited[102][102];
bool keys[26];
vector<pair<int, int>> doors[26];
queue<pair<int, int>> q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void init(int h, int w) {
    for (int i = 0; i < 26; i++) {
        keys[i] = false;
        doors[i].clear();
    }

    for (int y = 0; y <= h+1; y++) {
        for (int x = 0; x <= w+1; x++) {
            map[y][x] = '.';
            visited[y][x] = false;
        }
    }
}

int search(int h, int w) {
    int x, y, nx, ny;
    int count = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        map[y][x] = '.';
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx <= w+1 && 0 <= ny && ny <= h+1
                    && !visited[ny][nx] && map[ny][nx] != '*') {
                if ('A' <= map[ny][nx] && map[ny][nx] <= 'Z') {
                    doors[map[ny][nx]-'A'].emplace_back(nx, ny);
                }
                else {
                    if (map[ny][nx] == '$')
                        count++;
                    else if (map[ny][nx] != '.')
                        keys[map[ny][nx] - 'a'] = true;
                    q.emplace(nx, ny);
                }
                visited[ny][nx] = true;
            }
        }
    }

    return count;
}

void solution() {
    int T, h, w;
    string s;

    cin >> T;
    while (T--) {
        cin >> h >> w;
        init(h, w);
        for (int y = 1; y <= h; y++) {
            cin >> s;
            for (int x = 1; x <= w; x++) {
                map[y][x] = s[x-1];
            }
        }
        cin >> s;
        for (auto c: s)
            keys[c - 'a'] = true;

        int count = 0;
        q.emplace(0, 0);
        visited[0][0] = true;
        while (!q.empty()) {
            count += search(h, w);

            for (int i = 0; i < 26; i++) {
                if (keys[i] && !doors[i].empty()) {
                    for (auto d : doors[i])
                        q.emplace(d.first, d.second);
                    doors[i].clear();
                }
            }
        }

        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}