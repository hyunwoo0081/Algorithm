#include <iostream>
#include <algorithm>

using namespace std;

int inputs[1000];

void solution() {
    int N, L, limit, count;

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> inputs[i];
    sort(inputs, inputs + N);

    count = limit = 0;
    for (int i = 0; i < N; i++) {
        if (inputs[i] >= limit) {
            limit = inputs[i] + L;
            count++;
        }
    }
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}