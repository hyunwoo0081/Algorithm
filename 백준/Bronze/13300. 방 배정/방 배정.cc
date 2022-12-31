#include <iostream>

using namespace std;

int counts[2][6] = {0};

void solution() {
    int N, K, s, y, count;

    cin >> N >> K;
    while (N--) {
        cin >> s >> y;
        counts[s][y-1]++;
    }

    count = 0;
    for (auto &arr:counts)
        for (auto &p:arr)
            count += (p + K-1) / K;
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}