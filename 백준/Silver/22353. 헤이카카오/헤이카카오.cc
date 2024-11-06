#include <iostream>

using namespace std;

void solution() {
    double a, d, k, fail, result = 0;
    int times = 1;

    cin >> a >> d >> k;
    d = d / 100.;
    k = 1. + k/100.;
    fail = 1.;
    do {
        result += times * a * fail * d;
        fail *= 1.- d;
        d *= k;
        times++;
    } while (d < 1.);
    result += times * a * fail * min(1., d);

    cout.precision(8);
    cout << fixed << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}