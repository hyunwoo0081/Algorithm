#include <iostream>
#include <algorithm>
#define SIZE 200'000

using namespace std;

int arr[SIZE];
void solution() {
    int n, cnt, result = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        while (arr[i] % 2 == 0) {
            arr[i] /= 2;
        }
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            cnt = 1;
        } else {
            cnt++;
        }

        result = max(result, cnt);
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}