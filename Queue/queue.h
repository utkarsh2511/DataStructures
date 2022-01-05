typedef struct data {
	char name[16];
	unsigned int age;
}data;
typedef struct node {
	data d;
	struct node *next;
}node;
typedef struct queue {
	node *head;
	node *tail;
}queue;

void qinit(queue *q);
void enq(queue *q, data d);
data deq(queue *q);
int qfull(queue *q);
int qempty(queue *q);
