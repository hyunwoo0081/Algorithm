#include <iostream>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    for (int y = 0; y < N; y++) {
        if (y % 2) {
            for (int x = N-1; x >= 0; x--)
                cout << y*N+x+1 << ' ';
        }
        else {
            for (int x = 0; x < N; x++)
                cout << y*N+x+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}