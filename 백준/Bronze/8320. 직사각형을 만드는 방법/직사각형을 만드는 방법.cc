#include <iostream>

using namespace std;

void solution() {
    int N, count = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j*j <= i; j++)
            count += (i % j == 0);
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}