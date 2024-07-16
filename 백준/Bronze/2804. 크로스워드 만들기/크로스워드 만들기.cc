#include <iostream>

using namespace std;

int main() {
    string A, B;
    int I, J, x, y;
    
    cin >> A >> B;
    for (I = 0; I < A.length(); I++) {
        for (J = 0; J < B.length(); J++) {
            if (A[I] == B[J])
                break;
        }
        
        if (J < B.length()) break;
    }
    
    for (y = 0; y < B.length(); y++) {
        for (x = 0; x < A.length(); x++) {
            cout << (y == J ? A[x] : x == I ? B[y] : '.');
        }
        cout << '\n';
    }

    return 0;
}