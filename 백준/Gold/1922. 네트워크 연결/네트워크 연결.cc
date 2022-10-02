#include <iostream>
#include <queue>
#define SIZE 100'000

using namespace std;

priority_queue<pair<int, int>> q;
int unions[SIZE] = {0};

void initUnions() {
    for (int &uni : unions)
        uni = -1;
}

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnions(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b) return false;

    if (unions[a] < unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[b]-1, unions[a]);
        unions[a] = b;
    }

    return true;
}

void solution() {
    int N, M, a, b, c;

    initUnions();
    cin >> N >> M;
    while (M--) {
        cin >> a >> b >> c;
        a--, b--;
        q.emplace(-c, a*1000+b);
    }

    long long minDist = 0;
    while (N > 1) {
        c = -q.top().first;
        a = q.top().second / 1000;
        b = q.top().second % 1000;
        q.pop();

        if (joinUnions(a, b)) {
            minDist += c;
            N--;
        }
    }

    cout << minDist;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}