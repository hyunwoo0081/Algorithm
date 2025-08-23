#include <iostream>

using namespace std;

int main() {
    int N, r, k, a, b, c;
    
    r = 0;
    cin >> N;
    while (N--) {
        a = b = c = 0;
        cin >> a >> b;
        a = max(a, b);
        b = 0;
        for (int i = 0; i < 5; i++) {
            cin >> k;
            if (b <= k) {
                c = b;
                b = k;
            }
            else if (c <= k) {
                c = k;
            }
        }
        r = max(r, a + b + c);
    }
    cout << r;

    return 0;
}