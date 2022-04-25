#include <stdio.h>

int main(){
	int N, M;

	scanf("%d %d", &N, &M);
	//가로 길이에 따라 최댓값을 구하는 방법이 달라짐;

	if(N <= 1){
		printf("1");
	}
	else if(N == 2){
		printf("%d", (M+1)/2 > 4 ? 4 : (M+1)/2);
	}
	else{
		if(M >= 6){
			printf("%d", M-2);
		}
		else if(M == 5){
			printf("%d", M-1);
		}
		else{
			printf("%d", M);
		}
	}

	
	return 0;
}