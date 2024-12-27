#include <iostream>
#include <algorithm>
#define SIZE 100

using namespace std;

int arr[SIZE], brr[SIZE];
void solution() {
    int k, n;

    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        cin >> brr[i];

    sort(arr, arr + n);
    if (k == 1)
        sort(brr, brr + n);
    else
        sort(brr, brr + n, greater<int>());

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += max(arr[i], brr[i]);

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}