#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> arr;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

void solution() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr.begin(), arr.end(), compare);

        for (int i = 0; i < N; i++) {
            if (i != 0)
                cout << ", ";
            cout << arr[i].first;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}