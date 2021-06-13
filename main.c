#include <stdio.h>
#define SIZE 10000

int visited[SIZE];
char visitedType[SIZE];
char command[SIZE];
//
int queue[SIZE];
int front, back, size;

void initQueue(){
	front = 0;
	back = -1;
	size = 0;
}

void increase(int *a){
	(*a)++;
	if(*a >= SIZE) *a = 0;
}

void enqueue(int a){
	increase(&back);
	queue[back] = a;
	size++;
}

int dequeue(){
	int address = front;
	increase(&front);
	size--;
	return queue[address];
}


//command DSLR;
int commandD(int a){
	return (2*a) % SIZE;
}

int commandS(int a){
	--a;
	if(a < 0) return 9999;
	return a;
}

int commandL(int a){
	return (a%1000)*10 + a/1000;
}

int commandR(int a){
	return (a%10)*1000 + a/10;
}

void initArray(){
	int i;
	for(i = 0; i < SIZE; i++){
		visited[i] = -1;
		visitedType[i] = 0;
	}
}

void addPath(int cOut, int num, char type){
	if(visited[cOut] == -1){
		visited[cOut] = num;
		visitedType[cOut] = type;
		enqueue(cOut);
	}
}

void findPath(int from, int to){
	int num, fn;
	initQueue();

	enqueue(from);
	visited[from] = -2;
	visitedType[from] = '\0';

	while(size > 0){
		num = dequeue();
		
		fn = commandD(num);
		addPath(fn, num, 'D');
		if(fn == to) break;

		fn = commandS(num);
		addPath(fn, num, 'S');
		if(fn == to) break;

		fn = commandL(num);
		addPath(fn, num, 'L');
		if(fn == to) break;

		fn = commandR(num);
		addPath(fn, num, 'R');
		if(fn == to) break;
	}

	fn = to;
	num = 0;
	while(visitedType[fn] != '\0'){
		command[num] = visitedType[fn];
		fn = visited[fn];
		num++;
	}

	for(num -= 1; num >= 0; num--){
		printf("%c", command[num]);
	}
	printf("\n");

}

int main() {
	int T, A, B;

	scanf("%d", &T);
	for(; T >= 0; T--){
		scanf("%d %d", &A, &B);
		initArray();
		findPath(A, B);
	}
	

	return 0;
}