#include <iostream>

using namespace std;

int main() {
    long long y1, m1, d1, ss, y2, m2, d2, dif;
    
    cin >> d1 >> m1 >> y1 >> ss;
    cin >> d2 >> m2 >> y2;
    
    dif = (y2-y1)*360 + (m2-m1)*30 + (d2-d1);
    ss--;
    
    cout << (dif+ss) % 7 + 1;

    return 0;
}