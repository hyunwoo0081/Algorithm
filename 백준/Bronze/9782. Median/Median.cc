#include <iostream>

using namespace std;

int arr[100];

int main() {
    int N, t=0;
    
    cin >> N;
    while (N) {
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        cout.precision(1);
        cout << "Case " << ++t << ": " << fixed;
        
        if (N % 2)
            cout << (double) arr[N/2] << '\n';
        else
            cout << (arr[N/2-1] + arr[N/2])/2. << '\n';
        
        cin >> N;
    }

    return 0;
}