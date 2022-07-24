#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> blocks;

void solution() {
    int x, n, l1, l2, a, i, j;

    while (cin >> x >> n) {
        x *= 10'000'000;
        blocks.clear();
        for (i = 0; i < n; i++) {
            cin >> a;
            blocks.push_back(a);
        }
        sort(blocks.begin(), blocks.end());

        l1 = l2 = -1;
        i = 0, j = n-1;
        while (i < j) {
            if (blocks[i]+blocks[j] > x) {
                j--;
            }
            else if (blocks[i]+blocks[j] < x) {
                i++;
            }
            else {
                if (abs(l1-l2) <= abs(blocks[i]-blocks[j])) {
                    l1 = blocks[i];
                    l2 = blocks[j];
                }
                i++, j--;
            }
        }

        if (l1 == -1)
            cout << "danger\n";
        else
            cout << "yes " << l1 << ' ' << l2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}