#include <iostream>

using namespace std;

int main() {
    int arr[3], maxN, sum = 0;
    
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (i == 0 || maxN < arr[i])
            maxN = arr[i];
    }
    
    cout << 3*maxN - sum;

    return 0;
}