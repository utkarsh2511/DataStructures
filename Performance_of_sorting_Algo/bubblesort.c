#include <stdio.h>
#include<stdlib.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)       
	        for (j = 0; j < n - i - 1; j++) 
           		if (arr[j] > arr[j + 1])
              			swap(&arr[j], &arr[j + 1]);
}
int main() {
	int *arr, n, count = 0, num, size = 1024; 
	arr = (int *)malloc(sizeof(int) * size);
	while(scanf("%d", &num) != EOF) {
		arr[count] = num;
		count++;
		if(count == size) {
			size *= 2;
			arr = (int *)realloc(arr, sizeof(int) * size);
			if(arr == NULL) {
				printf("Failed for %d\n", size);
				exit(1);
			}
		}
	}
	n = count;
	bubbleSort(arr, n);
	return 0;
}
