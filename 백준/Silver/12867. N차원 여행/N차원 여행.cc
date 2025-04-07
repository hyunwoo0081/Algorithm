#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<int> cords;
vector<int> dists;

bool addPair(int cord, int length) {
    for (auto & p : v) {
        if (p.first == cord) {
            p.second += length;
            return p.second == 0;
        }
    }

    v.emplace_back(cord, length);
    return false;
}

bool isZero() {
    for (auto p : v) {
        if (p.second != 0) {
            return false;
        }
    }

    return true;
}

void solution() {
    int N, M, cord;
    char c;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> cord;
        cords.push_back(cord);
    }

    for (int i = 0; i < M; i++) {
        cin >> c;
        dists.push_back(c == '+' ? 1 : -1);
    }

    bool canDuplicated = false;
    for (int start = 0; !canDuplicated && start < M-1; start++) {
        v.clear();
        addPair(cords[start], dists[start]);
        for (int end = start + 1; end < M; end++) {
            if (addPair(cords[end], dists[end]) && isZero()) {
                canDuplicated = true;
                break;
            }
        }
    }

    cout << !canDuplicated;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}