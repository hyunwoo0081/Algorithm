#include <iostream>

using namespace std;

int main() {
    int T, N, W, C, maxW, maxC;
    double maxV, V;
    
    cin >> T;
    while (T--) {
        maxW = maxC = maxV = 0;
        cin >> N;
        while (N--) {
            cin >> W >> C;
            V = (double) C / W;
            if (maxW == 0 || V < maxV || V == maxV && maxC > C) {
                maxV = V;
                maxW = W;
                maxC = C;
            }
        }
        cout << maxC << '\n';
    }

    return 0;
}