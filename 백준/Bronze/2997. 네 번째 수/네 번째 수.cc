#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[3];
    
    for (auto &a : arr) {
        cin >> a;
    }
    sort(arr, arr+3);
    
    if (arr[1]-arr[0] == arr[2]-arr[1])
        cout << arr[2] + arr[1]-arr[0];
    else if (arr[1]-arr[0] > arr[2]-arr[1])
        cout << arr[0] + arr[2]-arr[1];
    else
        cout << arr[1] + arr[1]-arr[0];
    
    return 0;
}