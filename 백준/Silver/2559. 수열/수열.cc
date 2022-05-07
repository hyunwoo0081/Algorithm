#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

queue<int> q;

void solution() {
    int N, K, i, sum, temp, max;

    cin >> N >> K;
    sum = 0;
    for (i = 0; i < K; ++i) {
        cin >> temp;
        q.push(temp);

        sum += temp;
    }
    max = sum;
    for (; i < N; ++i) {
        cin >> temp;
        q.push(temp);

        sum += temp;
        sum -= q.front();
        q.pop();
        
        if (max < sum) max = sum;
    }
    cout << max;
}

int main() {
    fastIO();
    solution();

    return 0;
}