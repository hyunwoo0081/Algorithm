#include <iostream>
#include <algorithm>
#define SIZE 200'000

using namespace std;
typedef long long ll;

int inputs[SIZE];

void solution() {
    int N;
    ll sum, minSum, minPosition;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> inputs[i];
    sort(inputs, inputs + N);

    sum = 0;
    for (int i = 1; i < N; i++)
        sum += inputs[i] - inputs[0];
    minSum = sum;
    minPosition = inputs[0];

    for (int i = 1; i < N; i++) {
        sum += (ll) (inputs[i] - inputs[i-1]) * (i-(N-i));
        if (minSum > sum) {
            minSum = sum;
            minPosition = inputs[i];
        }
    }

    cout << minPosition;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}