#include <iostream>
#include <algorithm>
#define SIZE 100000

using namespace std;

int arr[SIZE];
int main() {
    int N, i, j;
    
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
    i = j = N / 2;
    while (0 <= i || j < N) {
        if (i >= 0)
            cout << arr[i] << ' ';
        if (i != j && j < N)
            cout << arr[j] << ' ';
        i--, j++;
    }

    return 0;
}