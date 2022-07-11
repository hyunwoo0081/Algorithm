#include <iostream>

using namespace std;

void solution() {
    int A, I;

    cin >> A >> I;
    cout << A*(I-(A!=1)) + (A != 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}