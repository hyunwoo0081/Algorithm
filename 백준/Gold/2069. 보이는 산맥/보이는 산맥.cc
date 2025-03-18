#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;

void solution() {
    int N, sx, ex, exMax = -1;
    long long result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sx >> ex;
        arr.emplace_back(sx, ex);
    }

    sort(arr.begin(), arr.end());

    for (auto &m : arr) {
        sx = m.first;
        ex = m.second;

        if (ex <= exMax) continue;
        if (sx >= exMax)
            result += (ex-sx)*(ex-sx);
        else
            result += (ex-sx)*(ex-sx) - (exMax-sx)*(exMax-sx);

        exMax = ex;
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}