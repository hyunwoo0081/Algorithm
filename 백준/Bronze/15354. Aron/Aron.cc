#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int N, cnt = 0;
    char c, prevC = '\0';

    cin >> N;
    while (N--) {
        cin >> c;
        cnt += c != prevC;
        prevC = c;
    }
    cout << cnt + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}