#include <iostream>
#define SIZE 26
#define HEIGHT 1000

using namespace std;

char from[SIZE];
char to[SIZE];
char result[SIZE];
string maps[HEIGHT];
void solution() {
    int K, N;
    char tmp;
    string s;

    cin >> K >> N >> s;
    for (int i = 0; i < K; i++) {
        from[i] = 'A' + i;
        to[i] = s[i];
    }

    for (int n = 0; n < N; n++) {
        cin >> maps[n];
    }

    // find from
    int h = 0;
    while (maps[h][0] != '?') {
        for (int i = 1; i < K; i++) {
            if (maps[h][i-1] == '-') {
                tmp = from[i-1];
                from[i-1] = from[i];
                from[i] = tmp;
            }
        }
        h++;
    }

    h = N-1;
    while (maps[h][0] != '?') {
        for (int i = 1; i < K; i++) {
            if (maps[h][i-1] == '-') {
                tmp = to[i-1];
                to[i-1] = to[i];
                to[i] = tmp;
            }
        }
        h--;
    }


    bool isPossible = true;
    for (int i = 0; i < K-1; i++) {
        if (from[i] == to[i])
            result[i] = '*';
        else if (from[i] == to[i+1] && from[i+1] == to[i]) {
            result[i] = '-';
            tmp = from[i];
            from[i] = from[i+1];
            from[i+1] = tmp;
        }
        else {
            isPossible = false;
            break;
        }
    }


    if (!isPossible) {
        for (int i = 0; i < K-1; i++) {
            result[i] = 'x';
        }
    }

    for (int i = 0; i < K-1; i++) {
        cout << result[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}