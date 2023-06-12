#include <iostream>

using namespace std;

void solution() {
    int sum, minN, a;

    sum = 0, minN = 100;
    for (int i = 0; i < 4; i++) {
        cin >> a;
        sum += a;
        minN = min(minN, a);
    }
    sum -= minN;

    minN = 100;
    for (int i = 0; i < 2; i++) {
        cin >> a;
        sum += a;
        minN = min(minN, a);
    }
    sum -= minN;

    cout << sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}