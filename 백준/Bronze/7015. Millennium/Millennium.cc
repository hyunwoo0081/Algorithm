#include <iostream>

using namespace std;

int passed(int y, int m, int d) {
    int r = 0;
    
    for (int yy = 1; yy < y; yy++) {
        r += yy % 3 ? (5*19 + 5*20) : 10*20;
    }
    
    for (int i = 1; i < m; i++) {
        r += (i % 2 || y % 3 == 0) ? 20 : 19;
    }
    r += d-1;
    
    return r;
}

int main() {
    int T, y, m, d;
    
    cin >> T;
    while (T--) {
        cin >> y >> m >> d;
        
        cout << passed(1000,1,1)-passed(y,m,d) << '\n';
    }
    
    return 0;
}