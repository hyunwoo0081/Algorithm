#include <iostream>

using namespace std;
typedef long long ll;

int powMatrix[10][31];

int Limit = 1;
ll getMax(int x, int P, ll mul) {
    if (mul >= Limit || mul < 0)
        return -1;
    if (x == 2) {
        mul *= powMatrix[x][P];
        if (mul >= Limit || mul < 0)
            return -1;
        return mul;
    }

    ll result = -1;
    for (int i = 0; i <= P; i++)
        result = max(result, getMax(x-1, P-i, mul * powMatrix[x][i]));

    return result;
}

void solution() {
    int D, P;

    cin >> D >> P;
    while (D--) Limit *= 10;

    for (int i = 1; i < 10; i++) {
        powMatrix[i][0] = 1;
        for (int p = 1; p <= P; p++) {
            powMatrix[i][p] = powMatrix[i][p-1] * i;
            if (0 > powMatrix[i][p] || powMatrix[i][p] >= Limit)
                powMatrix[i][p] = -1;
        }
    }

    cout << getMax(9, P, 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}