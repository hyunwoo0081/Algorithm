#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp;
vector<pair<int, int>> paints;

int binarySearch(int num) {
    int lo, hi, mid;

    lo = 0, hi = dp.size();
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
        C = j >= 0 ? dp[j] : 0;
        H = i > 0 ? dp[i-1] : 0;

        dp.push_back(max(C+paints[i].second, H));
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