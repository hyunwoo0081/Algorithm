#include <stdio.h>
#define SIZE 100001
#define QUEUESIZE 200003

int queue[QUEUESIZE];
int queueFront, queueBack, queueSize;

void initQueue();
void increase(int *var);
void enqueue(int x);
int dequeue();

int isValid(int x){
	return x >= 0 && x < SIZE;
}

int bfs(int visited[], int N, int K){
	int tmp, newX;
	
	initQueue();
	enqueue(N);
	visited[N] = 1;
	
	while(queueSize > 0){
		tmp = dequeue();
		
		if(tmp == K) return visited[tmp]-1;
		
		newX = tmp-1;
		if(isValid(newX) && visited[newX] == 0){
			enqueue(newX);
			visited[newX] = visited[tmp]+1;
		}
		
		newX = tmp+1;
		if(isValid(newX) && visited[newX] == 0){
			enqueue(newX);
			visited[newX] = visited[tmp]+1;
		}
		
		newX = tmp*2;
		if(isValid(newX) && visited[newX] == 0){
			enqueue(newX);
			visited[newX] = visited[tmp]+1;
		}
	}
	
	return -1;
}

int main(){
	int visited[SIZE] = {0};
	int N, K;
	
	scanf("%d %d", &N, &K);
	printf("%d", bfs(visited, N, K));

	return 0;
}

void initQueue(){
	queueFront = 0;
	queueBack = -1;
	queueSize = 0;
}

void increase(int *var){
	if(*var >= QUEUESIZE){
		*var = 0;
	}
	else{
		(*var)++;
	}
}

void enqueue(int x){
	increase(&queueBack);
	queue[queueBack] = x;
	queueSize++;
}

int dequeue(){
	int pastFront = queueFront;
	increase(&queueFront);
	queueSize--;
	return queue[pastFront];
}