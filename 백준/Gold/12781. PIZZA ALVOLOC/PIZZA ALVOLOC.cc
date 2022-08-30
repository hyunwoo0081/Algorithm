#include <iostream>

using namespace std;

struct vec2 {
    int x=0, y=0;
};

int normalize(int x) {
    return x / abs(x);
}

int ccw(vec2 X, vec2 Y, vec2 Z) {
    return normalize((Y.x-X.x)*(Z.y-Y.y) - (Z.x-Y.x)*(Y.y-X.y));
}

void solution() {
    vec2 A, B, C, D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    cout << (ccw(A, B, C) * ccw(A, B, D) < 0 && ccw(C, D, A) * ccw(C, D, B) < 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}