#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    double a, b, tmp;
    
    cin >> N;
    while (N--) {
        cin >> a >> b;
        
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        
        if (abs(a/b - (1+sqrt(5))/2) <= 0.01) {
            cout << "golden\n";
        }
        else {
            cout << "not\n";
        }
    }

    return 0;
}