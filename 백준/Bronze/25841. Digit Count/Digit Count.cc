#include <iostream>

using namespace std;

int main() {
    int a, b, c, tmp, result = 0;
    
    cin >> a >> b >> c;
    for (; a <= b; a++) {
        tmp = a;
        while (tmp > 0) {
            result += tmp % 10 == c;
            tmp /= 10;
        }
    }
    cout << result;

    return 0;
}