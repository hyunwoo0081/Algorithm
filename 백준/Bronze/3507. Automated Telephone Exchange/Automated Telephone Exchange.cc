#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;
    
    cin >> N;
    for (int i = 0; i < 100; i++) {
        cnt += (N - i < 100);
    }
    cout << cnt;

    return 0;
}