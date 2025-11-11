#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, d, r;
    
    cin >> n >> a >> b >> c >> d;
    
    r = n/a * b + (n%a!=0)*b;
    r = min(r, n/c*d + (n%c!=0)*d);
    
    cout << r;

    return 0;
}