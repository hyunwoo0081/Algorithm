#include <iostream>

using namespace std;

int main() {
    int N, a, b, c, cnt = 0;
    
    cin >> N;
    
    for (a = 1; a < N-1; a++) {
        for (b = a; b < N-1 && N - a - b >= b; b++) {
            if (a + b <= N - a - b)
                continue;
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}