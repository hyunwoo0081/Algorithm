#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, x, y, z;
    bool count, color;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> x >> y >> z;
        
        count = a+b+c > x+y+z;
        color = a > x || (a==x && b>y) || (a==x && b==y && c > z);
        
        cout << a << ' ' << b << ' ' << c << ' ' << x << ' ' << y << ' ' << z << '\n';
        if (count && color)
            cout << "both";
        else if (count)
            cout << "count";
        else if (color)
            cout << "color";
        else
            cout << "none";
        cout << "\n\n";
    }
    
    return 0;
}