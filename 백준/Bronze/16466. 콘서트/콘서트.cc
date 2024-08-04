#include <iostream>
#include <algorithm>
#define SIZE 1000000

using namespace std;

int arr[SIZE];

int main() {
    int N, i, result;
    
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> arr[i];
        
    sort(arr, arr+N);
    
    result = N+1;
    for (i = 1; i <= N; i++) {
        if (arr[i-1] != i) {
            result = i;
            break;
        }
    }
    
    cout << result;

    return 0;
}