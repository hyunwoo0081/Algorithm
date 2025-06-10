#include <iostream>

using namespace std;

int main() {
    int T, N, M, i, a, s, b;
    
    cin >> T;
    while (T--) {
        cin >> N >> M;
        s = b = 0;
        for (i = 0; i < N; i++) {
            cin >> a;
            s = max(a, s);
        }
            
        for (i = 0; i < M; i++) {
            cin >> a;
            b = max(a, b);
        }
        
        cout << (s < b ? 'B' : 'S') << '\n';
    }

    return 0;
}