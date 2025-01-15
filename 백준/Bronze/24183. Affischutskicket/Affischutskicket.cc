#include <iostream>

using namespace std;

void solution() {
    int a, b, c;

    cin >> a >> b >> c;
    cout.precision(10);
    cout << fixed << 2*a*(0.229 * 0.324) + 2*b*(0.297 * 0.420) + c*(0.210 * 0.297);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}