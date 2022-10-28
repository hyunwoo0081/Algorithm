#include <stdio.h>
#define SIZE 500000

int brr[SIZE];
void merge(int *arr, int left, int mid, int right){
	int i = left, j = mid + 1, k = 0;
	while(i <= mid && j <= right){
		if(arr[i] <= arr[j]){
			brr[k++] = arr[i++];
		}else{
			brr[k++] = arr[j++];
		}
	}
	
	while(i <= mid){
		brr[k++] = arr[i++];
	}
	
	while(j <= right){
		brr[k++] = arr[j++];
	}
	
	k--;
	while(k >= 0){
		arr[left + k] = brr[k];
		k--;
	}
}

void mergeSort(int *arr, int left, int right){
	int mid;
	if(left < right){
		mid = (right + left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);
	}
	
}

int main() {
	int N, M, i, B, start, end, mid, min_i, max_i;
	int A[SIZE];
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", A + i);
	}
	mergeSort(A, 0, N-1);
	
	scanf("%d", &M);
	for(i = 0; i < M; i++){
		scanf("%d", &B);
		
		start = 0;
		end = N - 1;
		while(start < end){
			mid = (start + end)/2;
			if(A[mid] < B){
				start = mid + 1;
			}
			else if(A[mid] == B){
				end = mid;
			}
			else{
				end = mid - 1;
			}
		}
	
		if(A[start] != B){
			printf("0 ");
			continue;
		}
		else{
			min_i = start;
		}
	
	
	
		start = 0;
		end = N - 1;
		while(start < end){
			mid = (start + end + 1)/2;
			if(A[mid] < B){
				start = mid + 1;
			}
			else if(A[mid] == B){
				start = mid;
			}
			else{
				end = mid - 1;
			}
		}
	
		if(A[start] != B){
			printf("0 ");
		}
		else{
			max_i = start;
			printf("%d ", max_i - min_i + 1);
		}
	}
	
	return 0;
}