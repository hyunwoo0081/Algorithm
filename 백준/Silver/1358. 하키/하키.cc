#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int W, H, X, Y;

bool isCircleInside(int rx, int ry, int r, int x,  int y) {
    return (rx-x)*(rx-x) + (ry-y)*(ry-y) <= r*r;
}

bool isInside(int x, int y) {
    int R = H / 2;
    if (X <= x && x <= X+W && Y <= y && y <= Y+H)
        return true;
    if (isCircleInside(X, Y+R, R, x, y))
        return true;
    if (isCircleInside(X+W, Y+R, R, x, y))
        return true;

    return false;
}

void solution() {
    int P, x, y;

    cin >> W >> H >> X >> Y >> P;

    int count = 0;
    while (P--) {
        cin >> x >> y;
        if (isInside(x, y)) count++;
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}