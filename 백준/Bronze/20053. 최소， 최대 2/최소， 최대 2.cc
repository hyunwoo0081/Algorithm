#include <iostream>

using namespace std;

void solution() {
    int T, N, a, maxN, minN;

    cin >> T;
    while (T--) {
        cin >> N;

        maxN = -1'000'000;
        minN = 1'000'000;

        while (N--) {
            cin >> a;
            maxN = max(maxN, a);
            minN = min(minN, a);
        }

        cout << minN << ' ' << maxN << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}