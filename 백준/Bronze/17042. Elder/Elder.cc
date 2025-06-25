#include <iostream>

using namespace std;

bool isM[26] = {false};
int main() {
    int N, r = 1;
    char M, a, b;
    
    cin >> M >> N;
    isM[M-'A'] = true;
    while (N--) {
        cin >> a >> b;
        if (b == M) {
            M = a;
            isM[M-'A'] = true;
        }
    }
    
    r = 0;
    for (auto c : isM)
        r += c;
    
    cout << M << '\n' << r;

    return 0;
}