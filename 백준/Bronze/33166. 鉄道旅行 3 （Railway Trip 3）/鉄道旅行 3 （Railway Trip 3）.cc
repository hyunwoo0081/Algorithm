#include <iostream>

using namespace std;

int main() {
    int P, Q, A, B;
    
    cin >> P >> Q >> A >> B;
    cout << min(P, Q) * A + max(0, Q-P) * B;

    return 0;
}