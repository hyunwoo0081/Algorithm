#include <iostream>

using namespace std;

void solution() {
    int T, N, P, prevN, len = 0;

    cin >> T;
    T--;
    cin >> N >> P;
    prevN = N;
    while (T--) {
        cin >> N >> P;
        
        if (P) {
            len = max(len, N-prevN);
            prevN = N;
        }
    }
    len = max(len, N-prevN);
    
    cout << len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}