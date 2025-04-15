#include <iostream>

using namespace std;

void solution() {
    long long N, mx, my, m, xi, yi, mi, t = 1;

    cin >> N;
    while (N > 0) {
        mx = my = m = 0;
        for (int i = 0; i < N; i++) {
            cin >> xi >> yi >> mi;

            mx += mi*xi;
            my += mi*yi;
            m += mi;
        }

        if (t != 1)
            cout << '\n';

        cout.precision(2);
        cout << "Case " << t << ": " << fixed << (double)mx/m << ' ' << (double)my/m;
        t++;

        cin >> N;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}