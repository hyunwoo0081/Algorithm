#include <iostream>

using namespace std;

void solution() {
    int N, px, py, a, maxN=0, mine;

    cin >> N >> py >> px;
    py--, px--;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
            cin >> a;
            if (x == px && y == py)
                mine = a;
            else if (x == px || y == py)
                maxN = max(maxN, a);
        }

    cout << (maxN <= mine ? "HAPPY" : "ANGRY");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}