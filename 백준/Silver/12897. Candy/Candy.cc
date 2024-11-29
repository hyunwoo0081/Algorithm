#include <iostream>
#define ll long long
#define MOD 1'000'000'007L

using namespace std;

void solution() {
    ll N, a, b;

    a = b = 2;
    cin >> N;
    for (int i = 1; i < N; i++) {
        a = (2 + 3*b) % MOD;
        b = a;
    }

    if (N == 1)
        cout << 1;
    else
        cout << a;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}