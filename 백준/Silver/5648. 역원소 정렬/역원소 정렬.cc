#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

vector<ll> arr;

ll getRev(ll N) {
    ll result = 0;
    while (N > 0) {
        result = result * 10 + N % 10;
        N /= 10;
    }

    return result;
}

void solution() {
    ll T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        arr.push_back(getRev(N));
    }

    sort(arr.begin(), arr.end());

    for (auto i : arr)
        cout << i << '\n';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}