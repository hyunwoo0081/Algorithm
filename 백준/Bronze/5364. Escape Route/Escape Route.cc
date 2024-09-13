#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, cx, cy, x, y, mx, my;
    double dist = 987654321, d;
    
    cin >> N >> cx >> cy;
    N--;
    while (N--) {
        cin >> x >> y;
        
        d = sqrt(pow(cx-x, 2) + pow(cy-y, 2));
        if (d < dist) {
            dist = d;
            mx = x;
            my = y;
        }
    }
    
    cout << cx << ' ' << cy << '\n';
    cout << mx << ' ' << my << '\n';
    cout.precision(2);
    cout << fixed << dist;

    return 0;
}