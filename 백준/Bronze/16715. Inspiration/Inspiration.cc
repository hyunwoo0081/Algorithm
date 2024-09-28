#include <iostream>

using namespace std;

void solution() {
    int N, r, n, s, result = 0, resultR = 2;

    cin >> N;
    for (r = 2; r <= N; r++) {
        n = N;
        s = 0;
        while (n > 0) {
            s += n % r;
            n /= r;
        }

        if (result < s) {
            result = s;
            resultR = r;
        }
    }
    cout << result << ' ' << resultR;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}