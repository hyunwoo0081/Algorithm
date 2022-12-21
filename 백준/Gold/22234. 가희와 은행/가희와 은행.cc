#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

queue<pair<int, int>> waits;
vector<tuple<int, int, int>> afters;

void solution() {
    int N, T, W, M, px, tx, cx, timer, afterP;

    cin >> N >> T >> W;
    while (N--) {
        cin >> px >> tx;
        waits.emplace(px, tx);
    }

    cin >> M;
    while (M--) {
        cin >> px >> tx >> cx;
        afters.emplace_back(make_tuple(cx, px, tx));
    }
    sort(afters.begin(), afters.end());


    afterP = 0;
    timer = 0;
    tx = 0;
    for (int w = 0; w < W; w++) {
        while (afterP < afters.size() && get<0>(afters[afterP]) == w) {
            waits.emplace(get<1>(afters[afterP]), get<2>(afters[afterP]));
            afterP++;
        }

        if (timer == 0 || tx == 0) {
            if (tx > 0)
                waits.emplace(px, tx);

            px = waits.front().first;
            tx = waits.front().second;
            waits.pop();
            timer = T;
        }
        timer--, tx--;
        cout << px << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}