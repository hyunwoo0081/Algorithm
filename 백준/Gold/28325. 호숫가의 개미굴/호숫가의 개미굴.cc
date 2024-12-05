#include <iostream>
#define SIZE 250000
#define ll long long

using namespace std;

ll C[SIZE];
ll visited(ll x, ll N) {
    if (C[x] != 0) return 0;

    C[x] = -1;
    return visited((x+1)%N, N) + visited((x+N-1)%N, N) + 1;
}

void solution() {
    ll result = 0, N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        result += C[i];
    }

    if (result == 0) {
        cout << max(1LL, N/2);
        return;
    }

    for (int i = 0; i < N; i++) {
        result += (visited(i, N) + 1) / 2;
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