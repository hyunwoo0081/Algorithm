#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, result = 2;
    cin >> N;
    for (int i = 1; i < N; i++) {
        result += i+1 - (i)/3;
    }
    
    cout << result;
    

    return 0;
}