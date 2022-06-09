#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> x;

void solution() {
    int N, a, b;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        x.push_back(a);
    }

    if (N == 1 || N == 2 && x[0] != x[1]) {
        cout << 'A';
        return;
    }
    if (N == 2 && x[0] == x[1]) {
        cout << x[0];
        return;
    }

    if (x[1]-x[0] != 0) {
        if ((x[2]-x[1])%(x[1]-x[0]) == 0) {
            a = (x[2]-x[1])/(x[1]-x[0]);
            b = x[1] - a*x[0];

            for (int i = 3; i < N; ++i) {
                if (x[i] != a*x[i-1]+b) {
                    cout << 'B';
                    return;
                }
            }
            cout << a*x[N-1]+b;
            return;
        }
        else {
            cout << 'B';
            return;
        }
    }
    else {
        for (int i = 1; i < N; ++i) {
            if (x[0] != x[i]) {
                cout << 'B';
                return;
            }
        }
        cout << x[0];
        return;
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}