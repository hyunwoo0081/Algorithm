#include <iostream>
#include <vector>

using namespace std;

vector<pair<string, int>> names;

string& find(int value) {
    int lo = 0, hi = names.size()-1, mid;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (names[mid].second < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return names[lo].first;
}

void solution() {
    int N, M, value;
    string name;

    cin >> N >> M;
    while (N--) {
        cin >> name >> value;
        if (names.empty() || names.back().second != value)
            names.emplace_back(name, value);
    }

    while (M--) {
        cin >> value;
        cout << find(value) << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}