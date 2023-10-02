#include <iostream>

using namespace std;

void solution() {
    int N, K, P, result, cnt;
    int arr[2500];

    cin >> N >> K >> P;
    for (int i = 0; i < N*K; i++)
        cin >> arr[i];

    result = 0;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < K; j++)
            cnt += arr[i*K + j];
        result += cnt >= P;
    }
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}