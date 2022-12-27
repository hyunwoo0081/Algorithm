#include <iostream>

using namespace std;

void solution() {
    int N, r, e, c;

    cin >> N;
    while (N--) {
        cin >> r >> e >> c;
        e -= c;
        if (r < e)
            cout << "advertise" << '\n';
        else if (r == e)
            cout << "does not matter" << '\n';
        else
            cout << "do not advertise" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}