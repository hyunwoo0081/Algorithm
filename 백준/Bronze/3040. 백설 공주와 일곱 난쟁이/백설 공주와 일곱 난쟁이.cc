#include <iostream>
#define SIZE 9

using namespace std;

int main() {
    int arr[SIZE], i, j, sum=0;
    
    for (auto &a : arr) {
        cin >> a;
        sum += a;
    }
    
    for (i = 0; i < SIZE; i++) {
        bool isMatch = false;
        for (j = i+1; j < SIZE; j++) {
            if (arr[i] + arr[j] == sum-100) {
                isMatch = true;
                break;
            }
        }
        
        if (isMatch) break;
    }
    
    for (int k = 0; k < SIZE; k++) {
        if (k == i || k == j) continue;
        cout << arr[k] << '\n';
    }
    
    return 0;
}