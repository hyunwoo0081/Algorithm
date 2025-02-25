#include <iostream>
#include <algorithm>
#define SIZE 200000

using namespace std;

int arr[SIZE];
void solution() {
    int N, K;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int idx = 0;
    for (idx = 0; idx < N && arr[idx] < K; idx++) {}

    int result = N - idx;
    int left = 0, right = idx-1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum >= K) {
            result++;
            left++;
            right--;
        } else {
            left++;
        }
    }

     cout << (result == 0 ? -1 : result);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}