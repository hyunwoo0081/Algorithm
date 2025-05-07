#include <iostream>

using namespace std;

int main() {
    int T, X, Y;
    
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++)
                cout << 'X';
            cout << '\n';
        }
        
        if (T != 0)
            cout << '\n';
    }
    return 0;
}