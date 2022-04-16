#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int tile[128][128] = {0};
int tileNum = 0;
int holeX, holeY;

void createTiles(int startX, int startY, int K, int emptyX, int emptyY) {
    int nStartX, nEndX, nStartY, nEndY, nextK;

    if (K == 2) {
        tileNum++;
        for (int i = 0; i < 4; ++i) {
            nEndX = startX + i/2;
            nEndY = startY + i%2;
            if (emptyX != nEndX || emptyY != nEndY)
                tile[nEndY][nEndX] = tileNum;
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        nextK = K/2;
        nStartX = startX + (i/2)*nextK;
        nEndX = nStartX + nextK - 1;
        nStartY = startY + (i%2)*nextK;
        nEndY = nStartY + nextK - 1;

        if (nStartX <= emptyX && emptyX <= nEndX && nStartY <= emptyY && emptyY <= nEndY)
            createTiles(nStartX, nStartY, nextK, emptyX, emptyY);
        else
            createTiles(nStartX, nStartY, nextK, startX+nextK-1+(i/2), startY+nextK-1+(i%2));
    }

    //빈칸 채우기
    tileNum++;
    for (int i = 0; i < 4; ++i) {
        nEndX = startX + nextK-1 + i/2;
        nEndY = startY + nextK-1 + i%2;
        if (tile[nEndY][nEndX] == 0)
            tile[nEndY][nEndX] = tileNum;
    }
}

void solution() {
    int K;

    cin >> K >> holeX >> holeY;
    K = 1 << K;
    holeX--, holeY--;

    tile[holeY][holeX] = -1;
    createTiles(0, 0, K, holeX, holeY);

    for (int y = K-1; y >= 0; --y) {
        for (int x = 0; x < K; ++x) {
            cout << tile[y][x] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}