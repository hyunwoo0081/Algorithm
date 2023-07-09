#include <iostream>

using namespace std;
typedef long long ll;

void solution() {
    ll T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        cout << N << " is " << (N%2 ? "odd" : "even") << "\n";
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}