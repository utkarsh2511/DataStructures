#include"integer.h"
#include<stdio.h>
#include<stdlib.h>
node *head;
node *tail;
void initInteger(Integer *a) {
	head = tail = *a = NULL;
}
void addDigit(Integer *a, char c) {
	if(c >= '0' && c <= '9') {
		node *tmp;
		unsigned int digit;
		tmp = (node *)malloc(sizeof(Integer));
		digit = c - '0';
		if(head == NULL) {
			head = tail = tmp;
			head -> num = digit;
			head -> next = NULL;
			head -> prev = NULL;
			*a = head;
			return;
		}
		tail -> next = tmp;
		tail -> next -> prev = tail;
		tail = tmp;
		tail -> next = NULL;
		tail -> num = digit;
		*a = head;
	}
	else
		return;
}
Integer createIntegerFromString(char *str) {
	int i = 0;
	Integer a;
	initInteger(&a);
	while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		addDigit(&a, str[i]);
		i++;
	}
	//printInteger(a);
	return a;
}
void printInteger(Integer a) {
	node *p;
	p = a;
	while(p != NULL) {
		printf("%d", p -> num);
		p = p -> next;
	}
	printf("\n");
}
Integer addIntegers(Integer *a, Integer *b) {
	Integer c;
	unsigned int digit, carry = 0, no;
	node *tmp;
	while(((*a) -> next) != NULL) {
		(*a) = (*a) -> next;
	}
	while(((*b) -> next) != NULL) {
		(*b) = (*b) -> next;
	}
	initInteger(&c);
	while(((*a) != NULL) && ((*b) != NULL)) {
		no = ((*a) -> num) + ((*b) -> num) + carry;
		digit = no % 10;
		carry = no / 10;
		tmp = (node *)malloc(sizeof(node));
		if(head == NULL) {
			head = tail = tmp;
			head -> num = digit;
			head -> next = NULL;
			head -> prev = NULL;
			c = head;
		}
		else {
			head -> prev = tmp;
			tmp -> num = digit;
			tmp -> next = head;
			tmp -> prev = NULL;
			head = tmp;
			c = head;
		}
		(*a) = (*a) -> prev;
		(*b) = (*b) -> prev;
		if(((*a) != NULL) && ((*b) == NULL)) {
			while(*a != NULL) {
				digit = (*a) -> num + carry;
				tmp = (node *)malloc(sizeof(node));
				head -> prev = tmp;
				tmp -> num = digit;
				tmp -> next = head;
				tmp -> prev = NULL;
				head = tmp;
				c = head;
				carry = 0;
				(*a) = (*a) -> prev;
			}
			return c;
		}
		if(((*a) == NULL) && ((*b) != NULL)) {
			while(*b != NULL) {
				digit = (*b) -> num + carry;
				tmp = (node *)malloc(sizeof(node));
				head -> prev = tmp;
				tmp -> num = digit;
				tmp -> next = head;
				tmp -> prev = NULL;
				head = tmp;
				c = head;
				carry = 0;
				(*b) = (*b) -> prev;
			}
			return c;
		}
	}
	if(carry != 0) {
		tmp = (node *)malloc(sizeof(node));
		head -> prev = tmp;
		tmp -> num = carry;
		tmp -> next = head;
		tmp -> prev = NULL;
		head = tmp;
		c = head;
	}
	head = NULL;
	return c;	
	
}
Integer substractIntegers(Integer *a, Integer *b) {
	Integer c;
	unsigned int digit, borrow = 0, a1, b1;
	int no;
	node *tmp;
	while(((*a) -> next) != NULL) {
		(*a) = (*a) -> next;
	}
	while(((*b) -> next) != NULL) {
		(*b) = (*b) -> next;
	}
	initInteger(&c);
	while(((*a) != NULL) && ((*b) != NULL)) {
		a1 = (*a) -> num;
		b1 = (*b) -> num;
		no = ((*a) -> num) - ((*b) -> num);
		if(no >= 0) {
			digit = no % 10;
			tmp = (node *)malloc(sizeof(node));
			if(head == NULL) {
				head = tail = tmp;
				head -> num = digit;
				head -> next = NULL;
				head -> prev = NULL;
				c = head;
			}
			else {
				head -> prev = tmp;
				tmp -> num = digit;
				tmp -> next = head;
				tmp -> prev = NULL;
				head = tmp;
				c = head;
			}
			(*a) = (*a) -> prev;
			(*b) = (*b) -> prev;
			if(((*a) != NULL) && ((*b) == NULL)) {
				while(*a != NULL) {
					digit = (*a) -> num;
					tmp = (node *)malloc(sizeof(node));
					head -> prev = tmp;
					tmp -> num = digit;
					tmp -> next = head;
					tmp -> prev = NULL;
					head = tmp;
					c = head;
					(*a) = (*a) -> prev;
				}
			}
		}
		
		else {
			if(head == NULL) {
				(*a) = (*a) -> prev;
				no = 10 * ((*a) -> num) + a1 - b1;
				tmp = (node *)malloc(sizeof(node));
				head = tail = tmp;
				head -> num = no;
				head -> next = NULL;
				head -> prev = NULL;
				c = head;
				return c;
			}
			(*a) = (*a) -> prev;
			no = 10 * ((*a) -> num) + a1 - b1;
			tmp = (node *)malloc(sizeof(node));
			head -> prev = tmp;
			tmp -> num = no;
			tmp -> next = head;
			tmp -> prev = NULL;
			head = tmp;
			c = head;
		}	
	}
	head = NULL;
	return c;
}
void destroyInteger(Integer *a) {
	free(*a);
	free(head);
	free(tail);
}
int main() {

    Integer a, b, c;

    char ch;

    char str[64]; /* This size may change */


    initInteger(&a);

    initInteger(&b);


    while((ch = getchar()) != '\n')

        addDigit(&a, ch);

    scanf("%s", str);

    b = createIntegerFromString(str);
    //c = substractIntegers(&a, &b);
    //printInteger(c);
    //destroyInteger(&c);

    c = addIntegers(&a, &b); 

    printInteger(c);

    destroyInteger(&c);

   
}

