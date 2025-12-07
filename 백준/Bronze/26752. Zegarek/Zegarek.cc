#include <iostream>

using namespace std;

void printMM(int mm) {
    if (mm >= 10) cout << mm;
    else cout << "0" << mm;
}

int main() {
    int h, m, s;
    
    cin >> h >> m >> s;
    
    s++;
    if (s >= 60) {
        s %= 60;
        m++;
    }
    
    if (m >= 60) {
        m %= 60;
        h++;
    }
    
    if (h >= 24) {
        h %= 24;
    }
    
    printMM(h);
    cout << ":";
    printMM(m);
    cout << ":";
    printMM(s);
    
    return 0;
}