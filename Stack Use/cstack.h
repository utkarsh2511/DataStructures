#define MAX 16
typedef struct cstack {
	char a[MAX];
	int i;
}cstack;
/* The caller should ensure that
 * cinit() is called before any other function is called
 * cisfull() is checked before push() is called
 * cisemtpy() is checked before pop() is called 
 */
void cinit(cstack *s);
void cpush(cstack *s, char no);
char cpop(cstack *s);
int cisempty(cstack *s);
int cisfull(cstack *s);
