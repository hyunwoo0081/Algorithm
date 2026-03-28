#include <iostream>

using namespace std;

int main() {
    long long N, M;
    
    cin >> N >> M;
    cout << (N-1)*M + (M-1)*N + 2*(N-1)*(M-1);

    return 0;
}