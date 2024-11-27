#include <iostream>
#define SIZE 100'001
#define INF 987654321

using namespace std;

int visited[SIZE] = {0};
void solution() {
    int N, K, c;


    cin >> N >> K;
    for (int k = 0; k <= K; k++)
        visited[k] = INF;

    visited[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> c;
        for (int k = K; k >= c; k--) {
            visited[k] = min(visited[k], visited[k-c] + 1);
        }
    }

    if (visited[K] == INF)
        cout << -1;
    else
        cout << visited[K];
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}