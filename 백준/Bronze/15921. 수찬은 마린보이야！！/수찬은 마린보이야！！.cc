#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int N, a, sum = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
    }

    cout << (sum == 0 ? "divide by zero" : "1.00");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}