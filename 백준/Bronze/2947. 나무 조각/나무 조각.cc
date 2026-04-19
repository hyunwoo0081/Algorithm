#include <iostream>
#define SIZE 5

using namespace std;

int main() {
    int arr[SIZE];
    int tmp;
    
    for (auto &a : arr) {
        cin >> a;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                
                // print
                for (int k = 0; k < SIZE; k++) {
                    if (k != 0) cout << ' ';
                    cout << arr[k];
                }
                cout << '\n';
            }
        }
    }

    return 0;
}