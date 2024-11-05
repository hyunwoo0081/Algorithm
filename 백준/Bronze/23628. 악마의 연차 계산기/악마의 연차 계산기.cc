#include <iostream>

using namespace std;

void solution() {
    long long A, B, C, Y, M;
    int y1, m1, d1, y2, m2, d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    A = (y1 * 12 + m1)*30 + d1;
    B = (y2 * 12 + m2)*30 + d2;

    C = B-A;
    M = min(C/30, 36LL);
    Y = 0;
    for (int i = 0; i < C/360; i++)
        Y += i/2 + 15;

    cout << Y << ' ' << M << '\n';
    cout << C << "days";
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}