#include <stdio.h>
#include<stdlib.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
        	for (j = i + 1; j < n; j++)
          		if (arr[j] < arr[min_idx])
            			min_idx = j;
        	swap(&arr[min_idx], &arr[i]);
	}
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
        selectionSort(arr, n);
	return 0;
}
