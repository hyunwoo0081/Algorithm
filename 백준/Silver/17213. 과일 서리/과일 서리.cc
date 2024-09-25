#include <iostream>

using namespace std;

long long com[30][10];

long long getCom(int n, int r) {
    if (n == 0 || n == 1 || r == 0 || r == n)
        return 1;

    if (r > n/2)
        r = n - r;

    if (com[n][r])
        return com[n][r];

    return com[n][r] = getCom(n-1, r) + getCom(n-1, r-1);
}

void solution() {
    int N, M;

    cin >> N >> M;
    cout << getCom(M-1, N-1);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}