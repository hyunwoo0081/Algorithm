#include <iostream>

using namespace std;

int main() {
    int M, T, U, F, D, length = 0;
    char c;
    
    cin >> M >> T >> U >> F >> D;
    for (int i = 0; i < T; i++) {
        cin >> c;
        
        if (c == 'f') {
            length += 2*F;
        }
        else {
            length += U + D;
        }
        
        if (length > M) {
            cout << i;
            return 0;
        }
    }
    
    cout << T;

    return 0;
}