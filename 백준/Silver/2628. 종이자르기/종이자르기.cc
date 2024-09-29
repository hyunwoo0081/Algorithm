#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> xs;
vector<int> ys;

void solution() {
    int w, h, x, y, n, result = 0;

    cin >> w >> h >> n;
    while (n--) {
        cin >> x >> y;

        if (x == 0)
            ys.push_back(y);
        else
            xs.push_back(y);
    }
    xs.push_back(0);
    xs.push_back(w);
    ys.push_back(0);
    ys.push_back(h);

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());


    for (int i = 1; i < xs.size(); i++) {
        for (int j = 1; j < ys.size(); j++) {
            x = xs[i] - xs[i-1];
            y = ys[j] - ys[j-1];

            result = max(result, x*y);
        }
    }

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}