#include <iostream>
#include <algorithm>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<pair<int, int>> classes;
priority_queue<int> q;

void solution() {
    int N, a, b, count;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        classes.emplace_back(a, b);
    }
    sort(classes.begin(), classes.end());

    count = 1;
    q.push(-classes[0].second);
    for (int i = 1; i < N; ++i) {
        q.push(-classes[i].second);

        if(classes[i].first >= -q.top())
            q.pop();
        else
            count++;
    }

    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}