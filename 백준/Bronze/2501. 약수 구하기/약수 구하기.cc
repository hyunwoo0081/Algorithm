#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            if (++count == K) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;

    return 0;
}
