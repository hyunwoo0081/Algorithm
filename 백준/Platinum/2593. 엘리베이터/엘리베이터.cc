#include <iostream>
#include <queue>
#include <cstring>
#define E_SIZE 101
#define F_SIZE 100'001

using namespace std;

int elevator[E_SIZE][2];
int prevEle[F_SIZE];
int prevFloor[F_SIZE];
int dist[F_SIZE];
bool visitEle[E_SIZE] = {false};
queue<int> q;

bool isPossible(int floor, int ele) {
    return floor >= elevator[ele][0] && (floor - elevator[ele][0]) % elevator[ele][1] == 0;
}

void solution() {
    int N, M, A, B, floor, d;

    memset(prevEle, -1, sizeof prevEle);
    memset(prevFloor, -1, sizeof prevFloor);
    memset(dist, -1, sizeof dist);

    cin >> N >> M;
    for (int m = 1; m <= M; m++)
        cin >> elevator[m][0] >> elevator[m][1];
    cin >> A >> B;

    q.emplace(A);
    dist[A] = 0;
    while (!q.empty()) {
        floor = q.front();
        d = dist[floor];
        q.pop();

        for (int m = 1; m <= M; ++m) {
            if (visitEle[m] || !isPossible(floor, m)) continue;

            visitEle[m] = true;
            for (int nextFloor = elevator[m][0]; nextFloor <= N; nextFloor += elevator[m][1]) {
                if (dist[nextFloor] >= 0) continue;

                q.emplace(nextFloor);
                dist[nextFloor] = d+1;
                prevFloor[nextFloor] = floor;
                prevEle[nextFloor] = m;
            }
        }
    }

    cout << dist[B] << '\n';
    vector<int> stack;
    floor = B;
    while (floor != A && prevEle[floor] != -1) {
        stack.emplace_back(prevEle[floor]);
        floor = prevFloor[floor];
    }
    while (!stack.empty()) {
        cout << stack.back() << '\n';
        stack.pop_back();
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}