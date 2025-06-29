#include <iostream>

using namespace std;

int score(int a, int c, int r, int g, int b) {
    return a * (r*r + g*g + b*b) + c * min (r, min(g, b));
}

int main() {
    int T, a, c, r, g, b, result, f;
    string s;
    
    cin >> T;
    while(T--) {
        cin >> a >> c >> r >> g >> b;
        s = "RED";
        result = score(a, c, r+1, g, b);
        f = score(a, c, r, g+1, b);
        if (result < f) {
            s = "GREEN";
            result = f;
        }
        
        f = score(a, c, r, g, b+1);
        if (result < f) {
            s = "BLUE";
            result = f;
        }
        
        cout << s << '\n';
    }

    return 0;
}