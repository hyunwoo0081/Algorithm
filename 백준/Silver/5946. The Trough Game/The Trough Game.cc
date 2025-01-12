#include <iostream>
#define SIZE 100

using namespace std;

int map[SIZE][2];

void solution() {
    string s;
    int N, M, bits, result, cnt, tmp, ct;
    bool isSame;

    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        cin >> s >> map[m][1];

        bits = 0;
        for (auto c : s) {
            bits = 2 * bits + (c == '1');
        }
        map[m][0] = bits;
    }

    result = cnt = 0;
    for (int n = 0; n < (1 << N); n++) {
        isSame = true;
        for (int m = 0; m < M && isSame; m++) {
            tmp = n & map[m][0];
            ct = 0;
            for (int nn = 0; nn < N; nn++) {
                ct += (tmp & (1 << nn)) != 0;
            }

            isSame &= map[m][1] == ct;
        }

        if (isSame) {
            cnt++;
            result = n;
        }
    }

    if (cnt == 0) {
        cout << "IMPOSSIBLE";
    }
    else if (cnt == 1) {
        for (int nn = N-1; nn >= 0; nn--) {
            cout << ((result & (1 << nn)) != 0 ? '1' : '0');
        }
    }
    else {
        cout << "NOT UNIQUE";
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}