#include <iostream>

using namespace std;

char mappings[27];
char str[81];

void solution() {
    long long A, B;
    cin >> A >> B;
    cout << 1000*A + 10000*B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}