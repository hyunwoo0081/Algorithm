#include <iostream>
#include <algorithm>
#define SIZE 10000

using namespace std;

long long arr[SIZE];
void solution() {
    long long N, result;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    result = 0;
    for (int i = 1; i < N; i++) {
        result += i * (arr[i] - arr[N-i-1]);
    }

    cout << 2*result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}