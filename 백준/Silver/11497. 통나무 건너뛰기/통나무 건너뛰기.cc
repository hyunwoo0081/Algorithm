#include <iostream>
#include <algorithm>
#define SIZE 10000

using namespace std;

int inputs[SIZE];

void solution() {
    int T, N, i, result;

    cin >> T;
    while (T--) {
        cin >> N;
        for (i = 0; i < N; i++)
            cin >> inputs[i];
        sort(inputs, inputs+N);

        result = inputs[1] - inputs[0];
        for (i = 2; i < N; i++)
            result = max(result, inputs[i] - inputs[i-2]);
        result = max(result, inputs[N-1] - inputs[N-2]);

        cout << result << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}