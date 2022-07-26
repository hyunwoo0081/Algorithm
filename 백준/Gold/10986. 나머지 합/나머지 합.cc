#include <iostream>

using namespace std;

int counts[1000] = {1};

void solution() {
    int N, M, A, sum;
    long long cnt;

    cin >> N >> M;
    cnt = sum = 0;
    while (N--) {
        cin >> A;
        sum = (sum + A) % M;
        cnt += counts[sum];
        counts[sum]++;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}