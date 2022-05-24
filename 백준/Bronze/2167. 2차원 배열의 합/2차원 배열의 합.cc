#pragma warning(disable:4996)
#include<stdio.h>

int arr[300][300];

int main() {
    int i, j, x, y, N, M, K, sum, a, b;

    scanf("%d %d", &N, &M);
    for (x = 0; x < N; x++) {
        for (y = 0; y < M; y++) {
            scanf("%d", &arr[y][x]);
        }
    }

    scanf("%d", &K);
    while (K--) {
        scanf("%d %d %d %d", &a, &b, &x, &y);
        sum = 0;
        for (i = b - 1; i < y; i++) {
            for (j = a - 1; j < x; j++) {
                sum += arr[i][j];
            }
        }
        printf("%d\n", sum);
    }
}