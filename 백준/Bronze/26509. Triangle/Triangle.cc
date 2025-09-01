#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int a[3], b[3];
    
    cin >> T;
    while (T--) {
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        
        sort(a, a+3);
        sort(b, b+3);
        
        bool result = true;
        for (int j = 0; j < 3; j++) {
            result &= a[j] == b[j];
        }
        result &= a[0]*a[0] + a[1]*a[1] == a[2]*a[2];
        
        cout << (result ? "YES\n" : "NO\n");
    }
    
    return 0;
}