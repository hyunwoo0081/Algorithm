#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;
priority_queue<int> q;

void solution() {
    int N, vote, v;
    cin >> N >> vote;

    while (--N) {
        cin >> v;
        q.push(v);
    }

    int count = 0;
    while (!q.empty() && vote <= q.top()) {
        v = q.top()-1;
        q.pop();
        q.push(v);
        vote++;
        count++;
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}