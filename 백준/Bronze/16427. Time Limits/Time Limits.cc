#include <iostream>

using namespace std;

int main() {
    int n, s, a, result = 0;
    
    cin >> n >> s;
    while (n--) {
        cin >> a;
        result = max(result, a);
    }
    result *= s;
    
    result = result / 1000 + (result % 1000 > 0);
    cout << result;

    return 0;
}