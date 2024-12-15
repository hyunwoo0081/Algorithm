#include <iostream>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    for (int i = 0; i < N-1; i++)
        cout << i%2+1 << ' ';
    cout << N % 2 + 2;
    
    return 0;
}