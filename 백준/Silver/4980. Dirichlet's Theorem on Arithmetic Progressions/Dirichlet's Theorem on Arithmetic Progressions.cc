#include <iostream>
#define SIZE 1000000

bool isPrime[SIZE + 1] = {false};

using namespace std;

int main() {
    int a, d, n;
    
    for (int i = 2; i <= SIZE; i++) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i <= SIZE; i++) {
        for (int j = 2; i*j <= SIZE; j++) {
            isPrime[i*j] = false;
        }
    }
    
    
    cin >> a >> d >> n;
    while (a || d || n) {
        int i = 0;
        for (; n && a+d*i <= SIZE; i++) {
            if (isPrime[a+d*i]) n--;
        }
        i--;
        
        if (n)
            cout << -1 << '\n';
        else
            cout << a+d*i << '\n';
        
        cin >> a >> d >> n;
    }

    return 0;
}