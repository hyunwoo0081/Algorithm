#include <iostream>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    cout.precision(1);
    if (N <= 30)
        cout << fixed << N / 2.;
    else
        cout << fixed << 15 + (N-30)*3/2.0;

    return 0;
}