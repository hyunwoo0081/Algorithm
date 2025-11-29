#include <iostream>

using namespace std;

int main() {
    long long N;
    
    cin >> N;
    N *= N;
    if (N > 100000000) {
        cout << "Time limit exceeded";
    }
    else {
        cout << "Accepted";
    }
    
    return 0;
}