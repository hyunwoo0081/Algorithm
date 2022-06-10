#include <iostream>

using namespace std;

int ability[11][11];
int maxNum = 0;

int getMax(int sum, int depth, int visited) {
    if (depth == 11)
        return maxNum = max(maxNum, sum);

    for (int i = 0; i < 11; ++i) {
        if (!(visited & (1<<i)) && ability[i][depth] > 0) {
            getMax(sum+ability[i][depth], depth+1, visited|(1<<i));
        }
    }

    return maxNum;
}

void solution() {
    int Tc;
    cin >> Tc;
    while (Tc--) {
        for (auto &y: ability)
            for (auto &ab: y)
                cin >> ab;

        maxNum = 0;
        cout << getMax(0, 0, 0) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}