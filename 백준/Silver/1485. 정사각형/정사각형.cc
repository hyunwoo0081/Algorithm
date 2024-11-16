#include <iostream>

using namespace std;

long long pos[8];
int idx[4];

long long lanSquare(int p1, int p2) {
    long long x = pos[p1] - pos[p2];
    long long y = pos[p1+1] - pos[p2+1];

    return x*x + y*y;
}

bool canMakeSquare(int p) {
    if (p == 4) {
        for (int i = 0; i < 4; i++) {
            int curr = 2*idx[i];
            int next = 2*idx[(i+1)%4];
            int nnext = 2*idx[(i+2)%4];

            if (lanSquare(curr, next) != lanSquare(next, nnext))
                return false;
        }

        if (lanSquare(2*idx[0], 2*idx[2]) != lanSquare(2*idx[1], 2*idx[3]))
            return false;

        return true;
    }

    bool result = false;
    for (int i = 0; i < 4; i++) {
        bool isSelected = false;
        for (int j = 0; j < p; j++)
            isSelected |= idx[j] == i;

        if (isSelected) continue;

        idx[p] = i;
        result |= canMakeSquare(p+1);
    }

    return result;
}

void solution() {
    long long T;

    cin >> T;
    while (T--) {
        for (auto &a : pos)
            cin >> a;

        cout << canMakeSquare(0) << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}