#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[3];

void solution() {
    int N, a;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        arr[a % 3].push_back(a);
    }

    if ((arr[0].size() > arr[1].size() + arr[2].size() + 1) ||
        (arr[0].empty() && !arr[1].empty() && !arr[2].empty())) {
        cout << -1;
        return;
    }

    while (!arr[1].empty()) {
        if (arr[0].size() > 1) {
            cout << arr[0].back() << ' ';
            arr[0].pop_back();
        }

        cout << arr[1].back() << ' ';
        arr[1].pop_back();
    }

    if (!arr[0].empty()) {
        cout << arr[0].back() << ' ';
        arr[0].pop_back();
    }

    while (!arr[2].empty()) {
        cout << arr[2].back() << ' ';
        arr[2].pop_back();

        if (!arr[0].empty()) {
            cout << arr[0].back() << ' ';
            arr[0].pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}