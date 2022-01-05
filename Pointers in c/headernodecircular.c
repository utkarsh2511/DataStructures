#include<stdio.h>
#include<stdlib.h>
int main() {
	typedef struct data {
		char name;
		struct data *p;
		}data;
	data a;
	data *b;
	int i=0, n = 0;
	char c;
	b = &a;
	scanf("%d", &n);
	a.p = &a;
	while(i != n) {
		b -> p = (data *)malloc(sizeof(data));
		scanf(" %c", &c);
		b -> p ->name = c;
		b = b->p;
		i++;
	}
	b -> p = &a; 
	b = NULL;
	return 0;
}
