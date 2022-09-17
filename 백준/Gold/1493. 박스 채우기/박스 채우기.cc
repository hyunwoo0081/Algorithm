#include <iostream>

using namespace std;
typedef long long ll;

int cubeCounts[21] = {0};

ll getMinCount(int l, int w, int h) {
    if (!l || !w || !h) return 0;

    for (int i = 20; i >= 0; i--) {
        int len = 1 << i;
        if (cubeCounts[i] > 0 && l >= len && w >= len && h >= len) {
            ll count = 1, cube;
            cubeCounts[i]--;

            cube = getMinCount(l-len, w, len);
            if (cube >= 0) count += cube;
            else return -1;

            cube = getMinCount(len, w-len, len);
            if (cube >= 0) count += cube;
            else return -1;

            cube = getMinCount(l, w, h-len);
            if (cube >= 0) count += cube;
            else return -1;

            return count;
        }
    }
    return -1;
}

void solution() {
    int l, w, h, n, a, b;

    cin >> l >> w >> h >> n;
    while (n--) {
        cin >> a >> b;
        cubeCounts[a] += b;
    }

    cout << getMinCount(l, w, h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}