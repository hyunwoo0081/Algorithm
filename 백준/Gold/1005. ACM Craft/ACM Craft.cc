#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> edge[1001];
int buildTime[1001];
bool isUpdated[1001];

void init(int N) {
    for (int i = 1; i <= N; ++i) {
        isUpdated[i] = false;
        edge[i].clear();
    }
}

int getBuildTime(int node) {
    if (isUpdated[node])
        return buildTime[node];

    int maxTime = 0;
    for (int next: edge[node]) {
        maxTime = max(maxTime, getBuildTime(next));
    }
    buildTime[node] += maxTime;
    isUpdated[node] = true;

    return buildTime[node];
}

void solution() {
    int T, N, K, X, Y, W;

    cin >> T;
    while (T--) {
        cin >> N >> K;
        init(N);
        for (int i = 1; i <= N; ++i) {
            cin >> buildTime[i];
        }
        for (int i = 1; i <= K; ++i) {
            cin >> X >> Y;
            edge[Y].push_back(X);
        }
        cin >> W;
        cout << getBuildTime(W) << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}