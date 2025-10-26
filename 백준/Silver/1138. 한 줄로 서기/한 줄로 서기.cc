#include <iostream>
#define SIZE 10

using namespace std;

int arr[SIZE];
int main() {
    int N, a;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        arr[i] = -1;
        
    
    for (int i = 0; i < N; i++) {
        cin >> a;
        
        int j = 0;
        int k = 0;
        for (j = 0; k <= a && j < N; j++) {
            k += arr[j] == -1;
        }
        j--;
        
        arr[j] = i+1;
    }
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}