#include <iostream>

using namespace std;


void solution() {
    long long W, N, w, h, area = 0;

    cin >> W >> N;
    while (N--) {
        cin >> w >> h;
        area += w * h;
    }

    cout << area / W;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}