#include <iostream>

using namespace std;

int main() {
    int N, i, a;
    long long total, result;
    int q[3];
    
    cin >> N;
    while (N) {
        total = result = i = 0;
        for (auto &t : q)
            t = 0;
        
        while (N--) {
            cin >> a;
            
            total += a - q[i%3];
            q[(i++)%3] = a;
            result = max(result, total);
        }
        
        cout << result << '\n';
        
        cin >> N;
    }

    return 0;
}