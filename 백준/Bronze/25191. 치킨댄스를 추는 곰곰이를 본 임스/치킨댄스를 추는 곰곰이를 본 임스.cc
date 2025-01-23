#include <iostream>

using namespace std;

int main() {
    int N, C, B;
    
    cin >> N >> C >> B;
    
    cout << min(N, C/2+B);
}