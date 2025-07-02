#include <iostream>

using namespace std;

int main() {
    int y = 2024, m = 0, n;
    
    cin >> n;
    
    n *= 7;
    y += n/12;
    m += n%12 + 1;
    cout << y << ' ' << m;

    return 0;
}