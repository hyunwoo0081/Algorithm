#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

priority_queue<int> q;

void solution() {
    int N, card, sum;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> card;
        q.push(-card);
    }

    sum = 0;
    while (--N) {
        card = q.top();
        q.pop();
        card += q.top();
        q.pop();
        q.push(card);
        sum += -card;
    }

    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}