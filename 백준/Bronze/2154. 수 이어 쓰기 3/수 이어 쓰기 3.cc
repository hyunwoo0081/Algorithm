#include <iostream>

using namespace std;

int main() {
    int n;
    string t;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t += to_string(i);
    }
    
    cout << t.find(to_string(n)) + 1;

    return 0;
}