#include <iostream>

using namespace std;

int main() {
    long long N, prev, now, result = 0;
    
    cin >> N >> prev;
    N--;
    while (N--) {
        cin >> now;
        result += (now - prev) * (now - prev);
        prev = now;
    }
    
    cout << result;
    
    return 0;
}