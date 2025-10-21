#include <iostream>

using namespace std;

int main() {
    int N, M, a, result;
    
    cin >> N >> M;
    while (N | M) {
        result = 0;
        for (int i = 0; i < N; i++) {
            cin >> a;
            result += min(a, M/N);
        }
        
        cout << result << '\n';
        cin >> N >> M;
    }
    
    return 0;
}