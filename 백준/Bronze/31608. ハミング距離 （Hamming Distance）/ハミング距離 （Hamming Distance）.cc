#include <iostream>

using namespace std;

int main() {
    int N, r = 0;
    string a, b;
    
    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        r += a[i] != b[i];
    }
    cout << r;
    
    return 0;
}