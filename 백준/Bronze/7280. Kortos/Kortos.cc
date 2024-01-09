#include <iostream>

using namespace std;

void solution() {
    char c;
    int S, B, V, K, cnt;

    S = B = V = K = 0;
    for (int i = 0; i < 51; i++) {
        cin >> c >> cnt;

        switch (c) {
            case 'S': S += cnt;
                break;
            case 'B': B += cnt;
                break;
            case 'V': V += cnt;
                break;
            case 'K': K += cnt;
                break;
            default:
                break;
        }
    }

    if (S < 13*7)
        cout << "S " << 13*7 - S;
    else if (B < 13*7)
        cout << "B " << 13*7 - B;
    else if (V < 13*7)
        cout << "V " << 13*7 - V;
    else
        cout << "K " << 13*7 - K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}