#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
unsigned long get_time() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        unsigned long ret = tv.tv_usec;
        ret /= 1000;
        ret += (tv.tv_sec * 1000);
        return ret;
}
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
} 
void selectionSort(int arr[], int n) {
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
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
	long start_time = get_time();
        selectionSort(arr, n);
     	long end_time = get_time();
     	printf("%ld", end_time - start_time);
	return 0;
}
