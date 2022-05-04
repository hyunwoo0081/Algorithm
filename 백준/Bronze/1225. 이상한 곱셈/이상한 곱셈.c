#pragma warning(disable:4996)
#include<stdio.h>

int main() {
    int i, j;
    long long sum;
    int A[10] = { 0 }, B[10] = { 0 };
    char c;

    scanf("%c", &c);
    while (c != ' ') {
        A[c - '0']++;
        scanf("%c", &c);
    }
    
    scanf("%c", &c);
    while (c != '\n') {
        B[c - '0']++;
        scanf("%c", &c);
    }


    sum = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            sum += (long long) i * j * A[i] * B[j];
        }
    }
    printf("%lld", sum);

    return 0;
}