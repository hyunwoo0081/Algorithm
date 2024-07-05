#include <iostream>
#define ll long long;

using namespace std;

int main() {
    long long x1, x2, a, b, c, d, e, A, B, C;
    
    cin >> x1 >> x2 >> a >> b >> c >> d >> e;
    A = a / 3;
    B = (b-d) / 2;
    C = c-e;
    
    cout << (A*x2*x2*x2 + B*x2*x2 + C*x2) - (A*x1*x1*x1 + B*x1*x1 + C*x1);

    return 0;
}