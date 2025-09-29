#include <iostream>

using namespace std;

int main() {
    int a, b, x, y, r;
    
    cin >> a >> b >> x >> y;
    r = min(a+x+max(b,y), b+y+max(a,x))*2;
    cout << r;

    return 0;
}