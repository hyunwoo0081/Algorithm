#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int backtracking(int prev, int map, int M) {
    int minLen;
    if (M == 0) {
        int sum = 0;
        for (auto h: house) {
            minLen = 10000;
            for (int i = 0; i < chicken.size(); ++i) {
                if (map & (1 << i))
                    minLen = min(minLen, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
            }
            sum += minLen;
        }

        return sum;
    }

    minLen = 1000000;
    for (int i = prev+1; i <= chicken.size()-M; ++i) {
        minLen = min(minLen, backtracking(i, map|(1<<i), M-1));
    }

    return minLen;
}

void solution() {
    int N, M, map;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map;
            if (map == 1)
                house.emplace_back(x, y);
            else if (map == 2)
                chicken.emplace_back(x, y);
        }
    }

    cout << backtracking(-1, 0, M);
}

int main() {
    fastIO();
    solution();

    return 0;
}