#include<stdio.h>
#include"queue.h"
#include<stdlib.h>
void qinit(queue *q) {
	(q) -> head = (q) -> tail = NULL;
}
void enq(queue *q, data d) {
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp -> d = d;
	if((q) -> head == NULL) {
		(q) -> head = (q) -> tail = tmp;
		(q) -> tail -> next = (q) -> head;
		return; 
	}
	(q) -> tail -> next = tmp;
	(q) -> tail = tmp;
	(q) -> tail -> next = (q) -> head;
}
data deq(queue *q) {
	node *p;
	data d;
	p = (q) -> head;
	(q) -> head = (q) -> head -> next;
	(q) -> tail -> next = (q) -> head;
	if(p == (q) -> head)
		(q) -> head = (q) -> tail = NULL;
	d = p -> d;
	free(p);
	return d;
}
int qempty(queue *q) {
	if((q) -> head == NULL)
		return 1;
	else
		return 0;
}
int qfull(queue *q) {
	return 0;
}
