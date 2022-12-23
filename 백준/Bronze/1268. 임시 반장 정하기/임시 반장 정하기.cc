#include <iostream>
#define SIZE 1000

using namespace std;

bool sames[SIZE][SIZE] = {false};
int map[SIZE][SIZE];

void solution() {
    int N, index, maxS, sum;

    cin >> N;
    for (int y = 0; y < N; y++)
        for (int k = 0; k < 5; k++)
            cin >> map[y][k];

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            for (int k = 0; k < 5; k++)
                sames[y][x] |= map[y][k] == map[x][k];

    index = 0;
    maxS = 0;
    for (int y = 0; y < N; y++) {
        sum = 0;
        for (int x = 0; x < N; x++)
            sum += sames[y][x];

        if (sum > maxS) {
            index = y;
            maxS = sum;
        }
    }
    cout << index+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}