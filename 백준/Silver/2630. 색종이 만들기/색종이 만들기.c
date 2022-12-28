#include <stdio.h>

//arr: 종이 배열, N: 종이 가로 길이
int whiteCount = 0, blueCount = 0;
void dividePaper(int arr[128][128], int N, int startX, int startY){
	int i, j, nextN;
	int startColor = arr[startX][startY];
	for(i = 0; startColor != -1 && i < N; i++){
		for(j = 0; startColor != -1 && j < N; j++){
			if(arr[startX + i][startY + j] != startColor)
				startColor = -1;
		}
	}

	if(startColor == -1){
		nextN = N / 2;
		dividePaper(arr, nextN, startX, startY);
		dividePaper(arr, nextN, startX + nextN, startY);
		dividePaper(arr, nextN, startX, startY + nextN);
		dividePaper(arr, nextN, startX + nextN, startY + nextN);
	}
	else if(startColor == 0){
		whiteCount++;
	}
	else{
		blueCount++;
	}
}

int main() {
	int arr[128][128];
	int N, i, j;

	scanf("%d", &N);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	whiteCount = blueCount = 0;
	dividePaper(arr, N, 0, 0);

	printf("%d\n%d", whiteCount, blueCount);

	return 0;
}