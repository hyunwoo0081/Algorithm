#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

priority_queue<ll> pq;

void solution() {
    int N, M;
    ll a, b, sum;

    cin >> N >> M;
    while (N--) {
        cin >> a;
        pq.push(-a);
    }

    while (M--) {
        a = -pq.top();
        pq.pop();
        b = -pq.top();
        pq.pop();
        a += b;

        pq.push(-a);
        pq.push(-a);
    }

    sum = 0;
    while (!pq.empty()) {
        sum += -pq.top();
        pq.pop();
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}