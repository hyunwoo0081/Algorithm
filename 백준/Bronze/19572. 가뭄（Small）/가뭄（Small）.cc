#include <iostream>

using namespace std;

void solution() {
    double d1, d2, d3, A, B, C;

    cin >> d1 >> d2 >> d3;

    A = (d2-d1+d3)/2.;
    B = (d1-d2+d3)/2.;
    C = (d1+d2-d3)/2.;

    if (A <= 0 || B <= 0 || C <= 0)
        cout << -1;
    else
    {
        cout << 1 << '\n';
        cout.precision(1);
        cout << fixed << C << ' ' << B << ' ' << A;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}