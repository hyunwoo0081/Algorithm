#include<stdio.h>

int main() {
    int map[100][100];
    int x, y, N, M, a;

    scanf("%d %d", &N, &M);
    for (y = 0; y < N; y++) {
        for (x = 0; x < M; x++) {
            scanf("%d", &map[y][x]);
        }
    }

    for (y = 0; y < N; y++) {
        for (x = 0; x < M; x++) {
            scanf("%d", &a);
            map[y][x] += a;
        }
    }

    for (y = 0; y < N; y++) {
        for (x = 0; x < M; x++) {
            printf("%d ", map[y][x]);
        }
        printf("\n");
    }
}