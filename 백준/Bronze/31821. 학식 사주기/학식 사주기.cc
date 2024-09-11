#include <iostream>

using namespace std;

long long prices[10];
int main() {
    long long N, M, idx, result = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> prices[i];
    
    cin >> M;
    while (M--) {
        cin >> idx;
        result += prices[idx-1];
    }
    
    cout << result;

    return 0;
}