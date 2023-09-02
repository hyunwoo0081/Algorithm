#include <iostream>

using namespace std;
typedef long long ll;

ll getMaxNum(ll N, ll K, ll arr[], ll depth, ll result) {
    ll maxNum = -1;
    if (depth == 0)
        return result <= N ? result : -1;

    for (ll i = 0; i < K; i++)
        maxNum = max(maxNum, getMaxNum(N, K, arr, depth-1, result*10 + arr[i]));

    return maxNum;
}

void solution() {
    ll N, K, result = 0;
    ll arr[3];

    cin >> N >> K;
    for (ll i = 0; i < K; i++)
        cin >> arr[i];

    for (ll k = 8; k > 0; k--)
        result = max(result, getMaxNum(N, K, arr, k, 0));
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}