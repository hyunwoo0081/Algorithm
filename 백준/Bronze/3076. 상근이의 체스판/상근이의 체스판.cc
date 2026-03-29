#include <iostream>

using namespace std;

int main() {
    int Y, X, ry, rx;
    
    cin >> Y >> X >> ry >> rx;
    for (int y = 0; y < Y; y++) {
        for (int yy = 0; yy < ry; yy++) {
            for (int x = 0; x < X; x++) {
                for (int xx = 0; xx < rx; xx++) {
                    cout << ((y+x)%2 ? '.' : 'X');
                }
            }
            cout << '\n';
        }
    }

    return 0;
}