#include <iostream>
#define SIZE 100'000

using namespace std;
typedef long long ll;

int arr[SIZE];
ll preSum[SIZE];
ll revSum[SIZE];

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        preSum[i] = revSum[i] = arr[i];
    }

    for (int i = 1; i < N; i++)
        preSum[i] += preSum[i-1];
    for (int i = N-2; i >= 0; i--)
        revSum[i] += revSum[i+1];

    ll maxCount = 0;
    for (int i = 1; i < N-1; i++)
        maxCount = max(maxCount, 2*preSum[N-1] - preSum[0] - preSum[i] - arr[i]);

    for (int i = N-2; i > 0; i--)
        maxCount = max(maxCount, 2*revSum[0] - revSum[N-1] - revSum[i] - arr[i]);

    for (int i = 1; i < N-1; i++)
        maxCount = max(maxCount, preSum[i] + revSum[i] - arr[0] - arr[N-1]);

    cout << maxCount;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}