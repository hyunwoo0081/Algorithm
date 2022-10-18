#include <stdio.h>
#define SIZE 1000000

int brr[SIZE];
void merge(int arr[], int start, int mid, int end){
	int i = start, j = mid+1, k = 0;
	
	while(i <= mid && j <= end){
		if(arr[i] < arr[j]){
			brr[k++] = arr[i++];
		}else{
			brr[k++] = arr[j++];
		}
	}

	while(i <= mid){
		brr[k++] = arr[i++];
	}

	while(j <= end){
		brr[k++] = arr[j++];
	}

	k--;
	while(k >= 0){
		arr[start + k] = brr[k];
		k--;
	}
}

void mergeSort(int arr[], int start, int end){
	int mid1;
	if(start < end){
		mid1 = (start + end) / 2;

		mergeSort(arr, start, mid1);
		mergeSort(arr, mid1+1, end);

		merge(arr, start, mid1, end);
	}
}

int main() {
	int arr[SIZE];
	int N, i;
	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", arr+i);
	}

	mergeSort(arr, 0, N-1);

	for(i = 0; i < N; i++){
		printf("%d\n", arr[i]);
	}

	return 0;
}
