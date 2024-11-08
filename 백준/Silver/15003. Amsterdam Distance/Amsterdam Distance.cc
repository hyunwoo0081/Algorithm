#include <iostream>

using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}

void solution() {
    int N, M, ax, ay, bx, by;
    double R, sx, sy, result, dist;
    const double pi = 3.1415926535;

    cin >> M >> N >> R;
    cin >> ax >> ay >> bx >> by;

    result = 987654321;
    sx = R / N;
    for (int r = min(ay, by); r >= 0; r--) {
        sy = r * sx *  pi / M;

        dist = (double)abs(ay-by)*sx + 2*abs(min(ay, by)-r)*sx + abs(ax-bx) * sy;
        result = min(result, dist);
    }

    cout.precision(14);
    cout << fixed;
    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}