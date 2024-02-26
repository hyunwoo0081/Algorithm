#include <iostream>

using namespace std;

void solution() {
    int T, N, P;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> P;

        cout << "Case " << t << ":";
        if (!(N/P) && !(N%P))
            cout << ' ' << 0;
        else {
            if (N/P)
                cout << ' ' << N/P;
            if (N%P > 0)
                cout << " " << N%P << "/" << P;
        }
        cout << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}