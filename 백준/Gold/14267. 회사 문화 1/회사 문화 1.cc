#include <iostream>
#define SIZE 100000

using namespace std;

int compliments[SIZE] = {0};
int parents[SIZE];

int getSum(int i) {
    if (parents[i] < 0)
        return compliments[i];

    compliments[i] += getSum(parents[i]);
    parents[i] = -1;
    return compliments[i];
}

void solution() {
    int n, m, i, w;
    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> parents[i];
        parents[i]--;
    }

    while (m--) {
        cin >> i >> w;
        compliments[--i] += w;
    }

    for (i = 0; i < n; i++) {
        cout << getSum(i) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}