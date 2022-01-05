#define N 50
typedef struct node {
	char string[N];
	struct node *next;
}node;
typedef node *list;
void init(list *l);
void insert(list *l, char *str, int pos);
char *remov(list *l, int pos);
void sort(list *l);
void reverse(list *l);
