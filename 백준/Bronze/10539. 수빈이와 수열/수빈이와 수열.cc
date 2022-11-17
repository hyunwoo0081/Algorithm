#include <iostream>

using namespace std;

void solution() {
    int N;
    long long sum, a;

    sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cout << (i+1)*a - sum << ' ';
        sum = (i+1)*a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
