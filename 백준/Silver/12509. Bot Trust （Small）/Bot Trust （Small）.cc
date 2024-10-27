#include <iostream>
#define SIZE 100

using namespace std;

void solution() {
    int T, N, bi, oi, ci, b, o, cnt;
    int P[SIZE];
    char c[SIZE];
    bool nextStep;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        bi = oi = ci = cnt= 0;
        b = o = 1;
        for (int n = 0; n < N; n++)
            cin >> c[n] >> P[n];

        while (ci < N) {
            // next bi, oi
            nextStep = false;
            while (bi < N && c[bi] != 'B') bi++;
            while (oi < N && c[oi] != 'O') oi++;

            if (bi < N) {
                if (P[bi] > b)
                    b++;
                else if (P[bi] < b)
                    b--;
                else if (bi == ci)
                    bi++, nextStep = true;
            }

            if (oi < N) {
                if (P[oi] > o)
                    o++;
                else if (P[oi] < o)
                    o--;
                else if (oi == ci)
                    oi++, nextStep = true;
            }

            if (nextStep) ci++;
            cnt++;
        }

        cout << "Case #" << t << ": " << cnt << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}