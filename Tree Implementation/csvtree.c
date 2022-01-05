#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct node {
	char str[16];
	int marks;
	struct node *left, *right;
}node;
typedef node *tree;
void insert(tree *t, char *str, int marks) {
	node *q, *p, *tmp;
	int result;
	tmp = (node *)malloc(sizeof(node));
	//tmp->str = (char *)malloc(strlen(str)+1);
	tmp->marks = marks;
	tmp->left = tmp->right = NULL;
	strcpy(tmp->str, str);
	p = *t;
	if(*t == NULL) {
		*t = tmp;
		return;
	}
	while(p) {
		q = p;
		result = strcmp(str, p->str);
		if(result < 0) 
			p = p->left;
		else
			p = p->right;
	}	
	if(result < 0)
		q->left = tmp;
	else
		q->right = tmp;
}

void inorderstore(tree t, int fw) {
	char str[16];
	if(t == NULL)
		return;
	inorderstore(t->left, fw);
	sprintf(str, "%s", t->str);
	write(fw, str, strlen(str));
	sprintf(str, "%d", t->marks);
	write(fw, ",", 1);
	write(fw, str, strlen(str));
	write(fw, "\n", 1);
	inorderstore(t->right, fw);
}
int main(int argc, char *argv[]) {
	if(argc < 3)
		return 1;
	int fd, i = 0, j = 0, l = 0, n = 0, k, fw;
	char arr[100], str[20];
	char *tok[10];
	tree t;
	fd = open(argv[1], O_RDONLY);
	fw = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed:\n");
		return errno;
	}
	if(fw == -1) {
		perror("open failed:\n");
		return errno;
	}
	while(read(fd, &arr[i], 1))
		i++;
	arr[i] = '\0';
	while(j < i) {
		if(arr[j] == '\n')
			n++;
		j++;
	}
	l = 0;
	while(n) { 
		i = 0;
		j = 0;
		while(arr[l] != '\n') {
			str[j] = arr[l];
			l++;
			j++;
		}
		l++;
		str[j] = '\0';
		char *token = strtok(str, ",");
		for(k = 0; k < 2; k++) {
			j = 0;
			tok[i] = token;
			token = strtok(NULL, ",");
			i++;
		}
		insert(&t, tok[0], atoi(tok[1]));
		n--;
	}
	inorderstore(t, fw);
	return 0;
}
