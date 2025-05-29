#include <iostream>

using namespace std;

int main() {
    int N, tmp, sum;
    
    cin >> N;
    while (true) {
        sum = 0;
        tmp = N;
        
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if (N % sum == 0)
            break;
        N++;
    }
    
    cout << N;

    return 0;
}