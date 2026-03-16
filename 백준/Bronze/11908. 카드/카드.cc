#include <iostream>
#include <algorithm>

using namespace std;

int arr[2222];
int main() {
    int N, result=0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
    for (int i = 0; i < N-1; i++) {
        result += arr[i];
    }

    cout << result;
    
    return 0;
}