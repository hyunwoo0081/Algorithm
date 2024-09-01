#include <iostream>

using namespace std;

int main() {
    int N, K;
    
    cin >> N;
    K = N / 2;
    for (int i = K; i > 0; i--) {
        for (int j = i; j <= N; j += K)
            cout << j << ' ';
    }
    
    if (K == 0)
        cout << 1;
        
    return 0;
}