typedef struct node {
	unsigned int num;
	struct node *next;
	struct node *prev;
}node;
typedef node* Integer;
void initInteger(Integer *a);//Call this Function every time you create a new Integer
void addDigit(Integer *a, char c);
Integer createIntegerFromString(char *str);
Integer addIntegers(Integer *a, Integer *b);
Integer substractIntegers(Integer *a, Integer *b);
void printInteger(Integer a);
void destroyInteger(Integer *a);

