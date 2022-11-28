#include <stdio.h>
#define SIZE 100001

int queue[SIZE];
int indexes[SIZE];
int front, back, size;

void initQueue() {
    front = 0;
    back = -1;
    size = 0;
}

void increase(int* val) {
    (*val) = (*val) < SIZE-1 ? (*val)+1 : 0;
}

void enqueue(int num) {
    increase(&back);
    queue[back] = num;
    size++;
}

int dequeue() {
    int tmp = queue[front];
    increase(&front);
    size--;
    return tmp;
}

int main() {
    int N, K, tmp;

    scanf("%d %d", &N, &K);

    for (tmp = 0; tmp < SIZE; tmp++) {
        indexes[tmp] = -1;
    }

    initQueue();
    enqueue(N);
    if(K == N) indexes[K] = N;
    while(indexes[K] == -1) {
        tmp = dequeue();

        if(tmp-1 >= 0 && indexes[tmp-1] == -1) {
            indexes[tmp-1] = tmp;
            enqueue(tmp-1);
        }
        if(tmp+1 < SIZE && indexes[tmp+1] == -1) {
            indexes[tmp+1] = tmp;
            enqueue(tmp+1);
        }
        if(tmp*2 < SIZE && indexes[tmp*2] == -1) {
            indexes[tmp*2] = tmp;
            enqueue(tmp*2);
        }
    }

    tmp = 0;
    while(K != N) {
        queue[tmp++] = K;
        K = indexes[K];
    }

    printf("%d\n%d", tmp, N);
    for(tmp--; tmp >= 0; tmp--)
        printf(" %d", queue[tmp]);
    
    return 0;
}