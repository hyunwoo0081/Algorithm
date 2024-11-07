#include <iostream>

using namespace std;

int main() {
    long long n, a, m, result = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (j == 0 || m < a)
                m = a;
        }
        result += max((long long) 0, m);
    }
    
    cout << result;
    
    return 0;
}