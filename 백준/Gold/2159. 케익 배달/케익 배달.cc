#include <iostream>
#define SIZE 100'000
#define INF 109876543210

using namespace std;
typedef long long ll;

ll dp[SIZE][5] = {0};
int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

void solution() {
    int N, sx, sy, ex, ey, nsx, nsy, nex, ney;
    ll result;

    cin >> N >> sx >> sy;
    // base case
    cin >> ex >> ey;
    for (int i = 0; i < 5; i++) {
        nex = ex + dx[i];
        ney = ey + dy[i];
        dp[0][i] = abs(nex-sx) + abs(ney-sy);
    }

    // inductive
    for (int n = 1; n < N; n++) {
        sx = ex, sy = ey;
        cin >> ex >> ey;

        for (int i = 0; i < 5; i++) {
            dp[n][i] = INF;
            nex = ex + dx[i];
            ney = ey + dy[i];

            for (int j = 0; j < 5; j++) {
                nsx = sx + dx[j];
                nsy = sy + dy[j];
                dp[n][i] = min(dp[n][i], dp[n-1][j] + abs(nex-nsx) + abs(ney-nsy));
            }
        }
    }

    result = dp[N-1][0];
    for (int i = 1; i < 5; i++)
        result = min(result, dp[N-1][i]);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}