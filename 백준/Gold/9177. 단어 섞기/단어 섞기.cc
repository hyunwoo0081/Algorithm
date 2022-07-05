#include <iostream>

using namespace std;

bool visited[201][201];
string a, b, target;

bool canMake(int ai, int bi, int ti) {
    if (ti >= target.length())
        return true;
    if (visited[ai][bi])
        return false;

    visited[ai][bi] = true;
    if (ai < a.length() && a[ai] == target[ti]
            && canMake(ai+1, bi, ti+1))
        return true;
    if (bi < b.length() && b[bi] == target[ti]
            && canMake(ai, bi+1, ti+1))
        return true;
    return false;
}

void solution() {
    int Tc;

    cin >> Tc;
    for (int i = 1; i <= Tc; ++i) {
        cin >> a >> b >> target;

        for (int y = 0; y <= a.length(); ++y) {
            for (int x = 0; x <= b.length(); ++x) {
                visited[y][x] = false;
            }
        }

        cout << "Data set " << i << ": " << (canMake(0, 0, 0) ? "yes\n" :  "no\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}