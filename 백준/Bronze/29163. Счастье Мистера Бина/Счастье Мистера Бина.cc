#include <iostream>

using namespace std;

void solution() {
    int n, a, odd, even;

    odd = even = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a % 2)
            odd++;
        else
            even++;
    }

    cout << (odd < even ? "Happy" : "Sad");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}