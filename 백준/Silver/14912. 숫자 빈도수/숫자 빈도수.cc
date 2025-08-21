#include <iostream>

using namespace std;

int main() {
    int N, d, tmp;
    long long r = 0;
    
    cin >> N >> d;
    for (int i = 1; i <= N; i++) {
        tmp = i;
        while (tmp > 0) {
            r += tmp % 10 == d;
            tmp /= 10;
        }
    }
    cout << r;

    return 0;
}