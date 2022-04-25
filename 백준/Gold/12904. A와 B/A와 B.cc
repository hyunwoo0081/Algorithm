#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    string S, T;
    int i, j;
    bool isB, isReversed, isSame;

    cin >> S >> T;

    isReversed = false;
    i = 0, j = T.size()-1;
    for (int k = 0; k < T.size()-S.size(); ++k) {
        if (isReversed) {
            isB = T[i] == 'B';
            i++;
        }
        else {
            isB = T[j] == 'B';
            j--;
        }

        if (isB)
            isReversed = !isReversed;
    }

    isSame = true;
    if (isReversed) {
        for (int k = 0; k < S.size() && isSame; ++k) {
            if (T[j] != S[k]) isSame = false;
            j--;
        }
    }
    else {
        for (int k = 0; k < S.size() && isSame; ++k) {
            if (T[i] != S[k]) isSame = false;
            i++;
        }
    }

    cout << isSame;
}


int main() {
    fastIO();
    solution();

    return 0;
}