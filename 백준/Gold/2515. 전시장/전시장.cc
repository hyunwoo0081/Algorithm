#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp;
vector<pair<int, int>> paints;

int binarySearch(int num) {
    int lo, hi, mid;

    lo = 0, hi = paints.size()-1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (paints[mid].first <= num)
            lo = mid+1;
        else
            hi = mid;
    }
    return hi-1;
}

void solution() {
    int N, S, H, C;

    cin >> N >> S;
    while (N--) {
        cin >> H >> C;
        paints.emplace_back(H, C);
    }
    sort(paints.begin(), paints.end());

    int j;
    for (int i = 0; i < paints.size(); i++) {
        j = binarySearch(paints[i].first - S);
        C = 0;
        if (j >= 0)
            C = dp[j];
        dp.push_back(max(C+paints[i].second, i > 0 ? dp[i-1] : 0));
    }
    cout << dp.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}