#include <iostream>
#define SIZE 100'000

using namespace std;

bool condition(int A, int X) {
    int sum = 0;
    while (A > 0) {
        sum += A % 10;
        A /= 10;
    }
    
    return X == sum;
}

int main() {
    int L, D, X;
    
    cin >> L >> D >> X;
    for (int i = L; i <= D; i++) {
        if (condition(i, X)) {
            cout << i <<'\n';
            break;
        }
    }
    
    for (int i = D; i >= L; i--) {
        if (condition(i, X)) {
            cout << i <<'\n';
            break;
        }
    }

    return 0;
}