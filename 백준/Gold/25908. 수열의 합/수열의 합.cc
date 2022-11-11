#include <iostream>

using namespace std;

void solution() {
    int S, E, count;
    int result = 0;

    cin >> S >> E;
    for (int i = 1; i <= E; i++) {
        count = E/i - (S-1)/i;
        result += i%2 ? -count : count;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
