#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> x;

void solution() {
    int N, K, a;
    cin >> N >> K;
    while (N--) {
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end(), greater<>());

    cout << x[K-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}