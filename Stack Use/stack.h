#define MAX 16
typedef struct stack {
	int a[MAX];
	int i;
}stack;
/* The caller should ensure that
 * init() is called before any other function is called
 * isfull() is checked before push() is called
 * isemtpy() is checked before pop() is called 
 */
void init(stack *s);
void push(stack *s, int no);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);
