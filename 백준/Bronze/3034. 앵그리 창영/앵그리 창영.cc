#include <iostream>
#include <cmath>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int N, W, H, L;
    double maxLength;

    cin >> N >> W >> H;
    maxLength = sqrt(W*W + H*H);

    while (N--) {
        cin >> L;
        if (L <= maxLength)
            cout << "DA\n";
        else
            cout << "NE\n";
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}