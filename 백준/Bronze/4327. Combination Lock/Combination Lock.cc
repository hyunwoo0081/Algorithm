#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, result;
    cin >> a >> b >> c >> d;
    while (a || b || c || d) {
        result = 720;
        result += ((a - b + 40) % 40) * 9;
        result += 360;
        result += ((c - b + 40) % 40) * 9;
        result += ((c - d + 40) % 40) * 9;
        
        cout << result << '\n';
        
        cin >> a >> b >> c >> d;
    }

    return 0;
}