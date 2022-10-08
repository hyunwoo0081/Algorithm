#include <iostream>

using namespace std;

void solution() {
    int N, F, result;
    cin >> N >> F;

    N = (N/100) * 100;
    result = (F - N%F) % F;

    if (result < 10)
        cout << 0 << result;
    else
        cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
