#include <iostream>

using namespace std;

void solution() {
    int sH, sM, sS, eH, eM, eS;

    for (int i = 0; i < 3; i++) {
        cin >> sH >> sM >> sS >> eH >> eM >> eS;
        eH -= sH;
        eM -= sM;
        eS -= sS;

        if (eS < 0) {
            eM--;
            eS += 60;
        }
        if (eM < 0) {
            eH--;
            eM += 60;
        }
        cout << eH << ' ' << eM << ' ' << eS << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
