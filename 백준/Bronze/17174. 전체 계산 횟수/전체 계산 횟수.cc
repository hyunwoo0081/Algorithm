#include <iostream>

using namespace std;

int main() {
    int N, M, result = 0;
    
    cin >> N >> M;
    while (N > 0) {
        result += N;
        N /= M;
    }
    cout << result;

    return 0;
}