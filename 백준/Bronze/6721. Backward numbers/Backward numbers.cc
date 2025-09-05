#include <iostream>

using namespace std;

int reverse(int n) {
    int r = 0;
    while (n > 0) {
        r = r*10 + n%10;
        n /= 10;
    }
    return r;
}

int main() {
    int T, a, b;
    
    cin >> T;
    while (T--) {
        cin >> a >> b;
        a = reverse(a);
        b = reverse(b);
        cout << reverse(a + b) << '\n';
    }

    return 0;
}