#include <iostream>
#define SIZE 100
using namespace std;

int h[SIZE][SIZE];

int dx[] = {0, 1, 1, 0};
int dy[] = {0, 0, 1, 1};

int main() {
    int N, x, y, mx, my, d;
    
    cin >> N;
    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            cin >> h[y][x];
            
    d = 0;
    mx = my = 0;
    for (int i = 0; i < 4; i++) {
        x = dx[i] * (N-1);
        y = dy[i] * (N-1);
        if (h[my][mx] > h[y][x]) {
            mx = x;
            my = y;
            d = i;
        }
    }
    
    if (d == 0) {
        for (y = 0; y < N; y++) {
            for (x = 0; x < N; x++)
                cout << h[y][x] << ' ';
            cout << '\n';
        }
    } else if (d == 1) {
        for (x = N-1; x >= 0; x--) {
            for (y = 0; y < N; y++)
                cout << h[y][x] << ' ';
            cout << '\n';
        }
    } else if (d == 2) {
        for (y = N-1; y >= 0; y--) {
            for (x = N-1; x >= 0; x--)
                cout << h[y][x] << ' ';
            cout << '\n';
        }
    } else {
        for (x = 0; x < N; x++) {
            for (y = N-1; y >= 0; y--)
                cout << h[y][x] << ' ';
            cout << '\n';
        }
    }

    return 0;
}