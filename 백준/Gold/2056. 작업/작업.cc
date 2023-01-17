#include <iostream>
#define SIZE 10000

using namespace std;

int dist[SIZE] = {0};

void solution() {
    int N, K, v, t, result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t >> K;
        while (K--) {
            cin >> v;
            v--;
            dist[i] = max(dist[i], dist[v]);
        }
        dist[i] += t;
        result = max(result, dist[i]);
    }
    
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}