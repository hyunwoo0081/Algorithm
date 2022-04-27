#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> sorted;

void solution() {
   int N, K, minTime, t;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        sorted.push_back(t);
    }

    for (int i = 0; i < N-1; ++i) {
        sorted[i] = sorted[i+1] - sorted[i] - 1;
    }
    sorted.pop_back();
    sort(sorted.begin(), sorted.end());

    minTime = N;
    for (int i = 0; i < N-K; ++i) {
        minTime += sorted[i];
    }

    cout << minTime;
}


int main() {
    fastIO();
    solution();

    return 0;
}