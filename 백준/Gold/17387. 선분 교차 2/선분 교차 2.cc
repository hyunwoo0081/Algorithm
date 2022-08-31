#include <iostream>

using namespace std;

int normalize(long long n) {
    return n < 0 ? -1 : (n == 0 ? 0 : 1);
}

int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    return normalize(((long long) A.first-B.first)*(C.second-B.second)
                    - ((long long) A.second-B.second)*(C.first-B.first));
}

bool isMeet(pair<int, int> d[]) {
    int a = ccw(d[0], d[1], d[2]) * ccw(d[0], d[1], d[3]);
    int b = ccw(d[2], d[3], d[0]) * ccw(d[2], d[3], d[1]);

    if (a == 0 && b == 0) {
        if (d[0] > d[1]) swap(d[0], d[1]);
        if (d[2] > d[3]) swap(d[2], d[3]);

        return !(d[3] < d[0] || d[1] < d[2]);
    }
    return a <= 0 && b <= 0;
}

void solution() {
    pair<int, int> dots[4];

    for (auto &d: dots)
        cin >> d.first >> d.second;
    cout << isMeet(dots);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}