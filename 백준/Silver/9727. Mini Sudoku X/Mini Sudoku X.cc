#include <iostream>

using namespace std;

int maps[6][6];
int visited[6];
void init() {
    for (auto &a : visited)
        a = false;
}

bool isSix() {
    bool result = true;
    for (auto a : visited)
        result &= a;
    return result;
}

void solution() {
    int T, i, j;
    bool result;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        result = true;
        for (i = 0; i < 6; i++)
            for (j = 0; j < 6; j++) {
                cin >> maps[i][j];
                maps[i][j]--;
            }

        // for (i = 0; i < 6; i++) {
        //     for (j = 0; j < 6; j++)
        //         cout << maps[i][j];
        //     cout << '\n';
        // }
        // cout << '\n';

        // diagonal
        init();
        for (i = 0; i < 6; i++)
            visited[maps[i][i]] = true;
        result &= isSix();

        init();
        for (i = 0; i < 6; i++)
            visited[maps[5-i][i]] = true;
        result &= isSix();

        // box
        for (i = 0; i < 6; i++) {
            init();
            for (j = 0; j < 6; j++)
                visited[maps[2*(i/2)+j/3][3*(i%2)+j%3]] = true;
            result &= isSix();
        }

        for (i = 0; i < 6; i++) {
            init();
            for (j = 0; j < 6; j++)
                visited[maps[i][j]] = true;
            result &= isSix();
        }

        for (i = 0; i < 6; i++) {
            init();
            for (j = 0; j < 6; j++)
                visited[maps[j][i]] = true;
            result &= isSix();
        }

        cout << "Case#"<< t << ": " << result << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}