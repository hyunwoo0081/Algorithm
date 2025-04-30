#include <iostream>

using namespace std;

int main() {
    int a, cnt1 = 0, cnt2 = 0;
    
    for (int i = 0; i < 3; i++) {
        cin >> a;
        if (a == 1) cnt1++;
        else cnt2++;
    }
    
    cout << (cnt1 >= cnt2 ? 1 : 2);
}