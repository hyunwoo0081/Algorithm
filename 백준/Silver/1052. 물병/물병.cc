#include <iostream>

using namespace std;

int getCount(int N) {
    int count = 0;
    for (int i = 0; i < 32; i++)
        count += (bool) (N & (1 << i));
    return count;
}

int getMinNum(int N) {
    for (int i = 0; i < 32; i++)
        if(N & (1 << i))
            return 1 << i;
    return 1 << 31;
}

void solution() {
    int N, K, count, num;

    count = 0;
    cin >> N >> K;
    while (getCount(N) > K) {
        num = getMinNum(N);
        N += num;
        count += num;
    }

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}