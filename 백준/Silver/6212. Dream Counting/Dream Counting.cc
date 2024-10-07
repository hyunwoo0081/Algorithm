#include <iostream>

using namespace std;

long long cnt[10] = {0};
void count(int n) {
    while (n > 0) {
        cnt[n%10]++;
        n /= 10;
    }
}

int main() {
    long long N, M, n;
    
    cin >> N >> M;
    for (int n = N; n <= M; n++) {
        count(n);
    }
    
    for (auto c : cnt) {
        cout << c << ' ';
    }

    return 0;
}