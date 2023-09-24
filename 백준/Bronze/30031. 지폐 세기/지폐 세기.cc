#include <iostream>

using namespace std;

void solution() {
    int N, w, h, result = 0;

    cin >> N;
    while (N--) {
        cin >> w >> h;

        switch (w) {
            case 136: result += 1000;
                break;
            case 142: result += 5000;
                break;
            case 148: result += 10000;
                break;
            default: result += 50000;
        }
    }
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}