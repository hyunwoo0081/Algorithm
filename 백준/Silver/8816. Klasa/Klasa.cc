#include <iostream>

using namespace std;

void solution() {
    long long T, N, result, i, two, tmp;

    cin >> T;
    while (T--) {
        cin >> N;
        result = 1;

        two = N/2;
        for (i = N/2+1; i <= N; i++) {
            tmp = i;
            while (two > 0 && tmp % 2 == 0) {
                tmp /= 2;
                two--;
            }

            result = (result * tmp)% 1000;
        }
        cout << result << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}