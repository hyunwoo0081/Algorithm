#include <iostream>

using namespace std;

void solution() {
    long long A, B, result;

    cin >> A >> B;
    result = 1;
    for (int i = 0; i < B; i++)
        result += (A - 2) * (i + 2) - (A - 3);
    cout << result;

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}