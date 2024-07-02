#include <iostream>

using namespace std;

int main() {
    int T, a, sum = 0;
    
    cin >> T;
    while (T--) {
        cin >> a;
        sum += a;
    }
    
    if (sum == 0)
    cout << "Stay";
    else if (sum < 0)
    cout << "Left";
    else
    cout << "Right";

    return 0;
}