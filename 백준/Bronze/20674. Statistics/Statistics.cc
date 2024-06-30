#include <iostream>

using namespace std;

int main() {
    int T, prev=987654321, a, count = 0;
    
    cin >> T;
    while (T--) {
        cin >> a;
        if (a > prev)
            count += a-prev;
        else
            prev = a;
    }
    cout << count;

    return 0;
}