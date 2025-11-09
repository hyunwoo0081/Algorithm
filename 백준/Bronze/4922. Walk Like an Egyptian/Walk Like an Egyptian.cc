#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        cout << n << " => " << n*n - (n-1) << '\n';
        cin >> n;
    }
    
    return 0;
}