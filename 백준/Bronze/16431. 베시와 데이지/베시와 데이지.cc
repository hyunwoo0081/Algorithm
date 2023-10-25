#include <iostream>

using namespace std;

void solution() {
    int bx, by, dx, dy, cx, cy, bl, dl;
    cin >> bx >> by >> dx >> dy >> cx >> cy;

    bl = max(abs(bx - cx), abs(by - cy));
    dl = abs(dx - cx) + abs(dy - cy);

    if (bl < dl)
        cout << "bessie";
    else if (bl == dl)
        cout << "tie";
    else
        cout << "daisy";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}