#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int A, B;

    cin >> A >> B;
    cout.precision(18);
    cout << 1. / (1 + pow(10, (B - A) / 400.)) << "\n";
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}