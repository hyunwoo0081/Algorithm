#include <iostream>

using namespace std;

int cost[] = {1, 5, 10, 20, 50, 100};

void solution() {
    int result = 0, index = 0, a;

    for (int i = 0; i < 6; i++) {
        cin >> a;

        a *= cost[i];
        if (result <= a) {
            result = a;
            index = i;
        }
    }

    cout << cost[index];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}