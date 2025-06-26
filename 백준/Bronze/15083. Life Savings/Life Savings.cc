#include <iostream>
#include <algorithm>

using namespace std;

int ps[3];

int main() {
    int c1, c2, c3;
    double r1, r2;
    
    for (auto &p : ps)
        cin >> p;
    cin >> c1 >> c2 >> c3;
    
    sort(ps, ps+3);
    
    r1 = 0;
    for (auto p : ps)
        r1 += p;
    r1 *= c1/100.;
    
    r2 = c2/100.*ps[2] + c3/100.*ps[1];
    r2 = max(r2, c2/100.*ps[1] + c3/100.*ps[2]);
    
    cout << (r1 > r2 ? "one " : "two ");
    cout.precision(2);
    cout << fixed << (r1 > r2 ? r1 : r2);

    return 0;
}