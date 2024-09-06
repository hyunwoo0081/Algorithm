// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    long long N, cnt = 0;
    
    cin >> N;
    cnt += (2*N + 1)*(2*N + 1);
    
    for (int a = -N; a <= N; a++) {
        if (a == 0) continue;
        
        for (int b = -N; b <= N; b++) {
            cnt += abs(1 - a - b) <= N;
        }
    }
    
    cout << cnt;
    
    return 0;
}