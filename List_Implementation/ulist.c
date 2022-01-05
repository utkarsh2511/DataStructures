#include"ulist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[N];
void init(list *l) {
	*l = NULL;
}
void insert(list *l, char *str, int pos) {
	if(pos < 0)
		return;
	node *tmp;
	node *p;
	node *q;
	int i = 0;
	p = *l;
	tmp = (node *)malloc(sizeof(node));
	strcpy(tmp -> string, str);
	if(pos == 0) {
		q = *l;
		*l = tmp;
		(*l) -> next = q;
		return;
	}
	while(i < pos - 1) {
		if(p == NULL)
			return;
		p = p -> next;
		i++;
	}
	if(p == NULL)
		return;
	q = p -> next;
	p -> next = tmp;
	tmp -> next = q; 
}
void printlist(list *l) {
	node *p;
	p = *l;
	while(p != NULL) {
		printf("%s ", p -> string);
		p = p -> next;
	}
	printf("\n");
}
char *remov(list *l, int pos) {
	node *p;
	node *q;
	int i = 0;
	if(*l == NULL)
		return NULL;
	p = *l;
	if(pos == 0) {
		p = p -> next;
		strcpy(s, (*l) -> string);
		free(*l);
		*l = p;
		return s;
	}
	while(i < pos - 1) {
		p = p -> next;
		i++;
	}
	q = p -> next -> next;
	strcpy(s, p -> next -> string);
	free(p -> next);
	p -> next = q;
	return s;
}
void sort(list *l) {
	node *p;
	node *q;
	char arr[N];
	p = *l;
	if(p == NULL)
		return;
	while(p -> next != NULL) {
		q = p -> next;
		while(q != NULL) {
			if(strcmp(p -> string, q -> string) > 0) {
				strcpy(arr, p -> string);
				strcpy(p -> string, q -> string);
				strcpy(q -> string, arr);
			}
			q = q -> next; 
		}
		p = p -> next;
	}
}
void reverse(list *l) {
	if(*l == NULL)
		return;
	int i = 0, j, k, m; 
	node *p;
	node *q;
	p = *l;
	char *str2;
	list l1;
	init(&l1);
	while(p != NULL) {
		str2 = remov(l, i);
		insert(l, str2, i);
		insert(&l1, str2, i);
		p = p -> next;
		i++;
	}
	p = *l;
	m = i;
	for(k = 0;k < m; k++) {
		for(j = 0; j < i - 1; j++) {
			p = p -> next;
		}
		i--;
		str2 = remov(&l1, 0);
		strcpy(p -> string, str2);
		p = *l;	
	}
}
	
