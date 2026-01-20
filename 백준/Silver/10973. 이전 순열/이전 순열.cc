#include <iostream>
#define SIZE 10000

using namespace std;

int arr[SIZE];
int main() {
    int N, idx, tdx, tmp;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    idx = N-2;
    while (idx >= 0 && arr[idx] < arr[idx+1]) {
        idx--;
    }
    
    if (idx <= -1) {
        cout << -1;
        return 0;
    }
    
    tdx = idx+1;
    for (int i = idx+1; i < N; i++) {
        if (arr[i] > arr[tdx] && arr[i] < arr[idx]) tdx = i;
    }
    tmp = arr[idx];
    arr[idx] = arr[tdx];
    arr[tdx] = tmp;
    
    // sort
    int left = idx+1;
    int right = N-1;
    while (left < right) {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}