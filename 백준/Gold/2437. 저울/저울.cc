#include <iostream>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int sorted[1000];

void solution() {
    int N, minNum;

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> sorted[i];
    sort(sorted, sorted+N);

    if (sorted[0] > 1) {
        cout << 1;
        return;
    }

    minNum = 1;
    for (int i = 1; i < N && minNum+1 >= sorted[i]; ++i) {
        minNum += sorted[i];
    }
    cout << minNum + 1;
}

int main() {
    fastIO();
    solution();

    return 0;
}