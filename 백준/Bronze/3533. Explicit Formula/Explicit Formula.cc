#include <iostream>

using namespace std;

int arr[10];

int main() {
    int i, j, k, result = 0;
    for (auto &a : arr) {
        cin >> a;
    }
    
    for (int i = 0; i < 10; i++)
        for (int j = i+1; j < 10; j++)
            result += arr[i] || arr[j];
    
    for (int i = 0; i < 10; i++)
        for (int j = i+1; j < 10; j++)
            for (int k = j+1; k < 10; k++)
                result += arr[i] || arr[j] || arr[k];
                
    cout << result % 2;

    return 0;
}