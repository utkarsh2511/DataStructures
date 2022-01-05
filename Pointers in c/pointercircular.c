#include<stdio.h>
#include<stdlib.h>
int main(){
	typedef struct data {
		char name;
		struct data *p;
		}data;
	data *p, *q;
	int n, i;
	char c;
	p = NULL;
	scanf("%d", &n);
	scanf("%c", &c);
	p = (data *)malloc(sizeof(data));
	q = p;
	p -> name = 'c';
	for(i = 1; i < n; i++){
		scanf(" %c", &c);
		q -> p = (data *)malloc(sizeof(data));
		q -> p -> name = c;
		q -> p -> p = p;
		q = q -> p;
	}
	q = NULL;
	return 0;
}




