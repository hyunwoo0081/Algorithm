#include <iostream>

using namespace std;

int main() {
    int N, a, ap, rj, iv;
    ap = rj = iv = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        switch(a) {
            case 1: ap++; break;
            case -1: rj++; break;
            case 0: iv++; break;
        }
    }
    
    if (2*iv >= N) {
        cout << "INVALID";
    }
    else if (rj >= ap) {
        cout << "REJECTED";
    }
    else {
        cout << "APPROVED";
    }

    return 0;
}