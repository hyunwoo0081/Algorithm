#include <iostream>

using namespace std;

bool visited[501][501][501] = {false};

void sortNum(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

bool stone(int a, int b, int c) {
    int na, nb, nc;
    if (a < 0 || b < 0 || c < 0) return false;
    if (visited[a][b][c]) return false;
    if (a == b && b == c) return true;

    visited[a][b][c] = true;

    na = a+a, nb = b-a, nc = c;
    sortNum(na, nb, nc);
    if(stone(na, nb, nc)) return true;

    na = a, nb = b+b, nc = c-b;
    sortNum(na, nb, nc);
    if(stone(na, nb, nc)) return true;

    na = a+a, nb = b, nc = c-a;
    sortNum(na, nb, nc);
    if(stone(na, nb, nc)) return true;

    return false;
}

void solution() {
    int a, b, c;
    cin >> a >> b >> c;
    sortNum(a, b, c);
    cout << stone(a, b, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}