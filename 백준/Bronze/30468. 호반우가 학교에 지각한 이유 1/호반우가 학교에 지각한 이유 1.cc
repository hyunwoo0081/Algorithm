#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, N;
    
    cin >> a >> b >> c >> d >> N;
    
    cout << max(0, N*4 - (a+b+c+d));

    return 0;
}