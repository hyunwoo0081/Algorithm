#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 100'000
#define INF 987654321

using namespace std;

long long positions[SIZE];
queue<long long> q;
void solution() {
    int N, K, i, j;

    cin >> N >> K;
    for (i = 0; i < N; i++)
        cin >> positions[i];
    sort(positions, positions+N);

    for (i = 1; i < N; i++)
        positions[i-1] = positions[i]-positions[i-1]-1;
    positions[N-1] = INF;
    sort(positions, positions+N, greater<>());

    for (i = 0; i < N; i++)
        q.push(positions[i]);

    long long dist = 1, result = 0;
    while (K > 0) {
        int qSize = q.size();

        for (i = 0; i < qSize; i++) {
            long long space = q.front();
            q.pop();

            for (j = 0; j < 2 && space > 0 && K > 0; j++) {
                result += dist;
                space--;
                K--;
            }

            if (space > 0)
                q.push(space);
        }

        dist++;
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}