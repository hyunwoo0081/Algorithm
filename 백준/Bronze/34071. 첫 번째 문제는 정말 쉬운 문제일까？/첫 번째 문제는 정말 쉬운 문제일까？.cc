#include <iostream>

using namespace std;

int main() {
    int N, f, a;
    bool ez, hard;
    ez = hard = true;
    
    cin >> N >> f;
    N--;
    while (N--) {
        cin >> a;
        
        ez &= f < a;
        hard &= f > a;
    }
    
    if (ez) cout << "ez";
    else if (hard) cout << "hard";
    else cout << '?';

    return 0;
}