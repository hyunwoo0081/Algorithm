#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll rx, ry, rz, n, r = 98765432109876, f;
    
    cin >> n;
    
    for (ll x = 1; x <= n; x++) {
        if (n % x != 0) continue;
        
        for (ll y = x; x*y <= n; y++) {
            if (n % (x*y) != 0) continue;
            
            ll z = n / (x*y);
            
            f = 2L*(x*y + y*z + z*x);
            if (r > f) {
                r = f;
                rx = x;
                ry = y;
                rz = z;
            }
        }
    }
    
    cout << rx << ' ' << ry << ' ' << rz;

    return 0;
}