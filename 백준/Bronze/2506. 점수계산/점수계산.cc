#include <iostream>

using namespace std;

int main() {
    int sum, k, N, x;

    cin >> N;
    sum = k = 0;
    while (N--) {
        cin >> x;
        if (x)
            sum += ++k;
        else
            k = 0;
    }
    cout << sum;
    
    return 0;
}
