#include <iostream>

using namespace std;

int main() {
    double e = 0;
    
    cout << "n e\n";
    cout << "- -----------\n";
    
    for (int i = 0; i <= 9; i++) {
        cout << i << ' ';
        
        double t = 1;
        for (int j = 2; j <= i; j++)
            t /= j;
        e += t;
        
        if (i >= 3)
            cout.precision(10);
        
        cout << e;
        if (i == 8)
            cout << 0;
        cout << '\n';
    }

    return 0;
}