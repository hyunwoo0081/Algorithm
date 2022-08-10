#include <iostream>

using namespace std;

bool map[100][100] = {false};

void solution() {
    int N, x, y;

    cin >> N;
    while (N--) {
        cin >> x >> y;

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                map[y+i][x+j] = true;
    }

    int area = 0;
    for (y = 0; y < 100; y++)
        for (x = 0; x < 100; x++)
            area += map[y][x];
    cout << area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}