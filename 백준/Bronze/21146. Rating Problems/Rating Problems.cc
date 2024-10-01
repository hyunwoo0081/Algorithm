#include <iostream>

using namespace std;

void solution() {
    int N, T, n, a, sum = 0;

    cin >> N >> T;
    n = N - T;
    while (T--) {
        cin >> a;
        sum += a;
    }

    cout << (double) (sum+(-3)*n) / N << ' ' << (double) (sum+3*n) / N;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}