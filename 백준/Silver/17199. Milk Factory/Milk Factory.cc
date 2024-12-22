#include <iostream>
#define SIZE 100

using namespace std;

bool hasPath[SIZE][SIZE] = {false, };

void solution() {
    int n, a, b;

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--, b--;
        hasPath[a][b] = true;
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hasPath[i][j] |= hasPath[i][k] && hasPath[k][j] || i == j;
            }
        }
    }

    bool isAllPath = true;
    for (int i = 0; i < n; i++) {
        isAllPath = true;
        for (int j = 0; j < n; j++) {
            isAllPath &= hasPath[j][i];
        }

        if (isAllPath) {
            cout << i+1;
            break;
        }
    }

    if (!isAllPath) {
        cout << -1;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}