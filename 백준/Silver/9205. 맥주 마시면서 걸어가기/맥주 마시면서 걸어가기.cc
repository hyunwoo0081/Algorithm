#include <iostream>
#include <vector>

using namespace std;

bool map[103][103] = {false};
vector<pair<int, int>> vertexes;

void solution() {
    int t, n, x, y, nx, ny;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n+2; i++) {
            cin >> x >> y;

            for (int j = 0; j < vertexes.size(); j++) {
                nx = vertexes[j].first;
                ny = vertexes[j].second;

                map[i][j] = abs(nx-x)+abs(ny-y) <= 1000;
                map[j][i] = map[i][j];
            }
            vertexes.emplace_back(x, y);
        }
        vertexes.clear();

        for (int k = 0; k < n+2; k++) {
            for (int i = 0; i < n+2; i++) {
                for (int j = 0; j < n+2; j++) {
                    if (map[i][k] && map[k][j])
                        map[i][j] = true;
                }
            }
        }

        cout << (map[0][n+1] ? "happy\n" : "sad\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}