#include <stdio.h>

int strcpr(char *a, char *b){
	int i;
	for(i = 0; a[i] != '\0' && b[i] != '\0' && a[i] == b[i]; i++);
	return a[i] == '\0' && b[i] == '\0';
}

int main() {
	int arrStack[10000];
	int pointer = -1, N, a;
	char commend[6];

	scanf("%d", &N);
	for(; N > 0; N--){
		getchar();
		scanf("%s", commend);
		if(strcpr(commend, "push")){
			scanf("%d", &a);
			arrStack[++pointer] = a;
		}
		else if(strcpr(commend, "pop")){
			printf("%d\n", pointer >= 0 ? arrStack[pointer--] : -1);
		}
		else if(strcpr(commend, "size")){
			printf("%d\n", pointer + 1);
		}
		else if(strcpr(commend, "empty")){
			printf("%d\n", pointer < 0);
		}
		else if(strcpr(commend, "top")){
			printf("%d\n", pointer >= 0 ? arrStack[pointer] : -1);
		}
	}

	return 0;
}
