#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define OPERAND 1
#define OPERATOR 2
#define END 3
#define ERR 4
#define BRACKET 5
typedef struct token {
	int type;  // OPERAND or OPERATOR or END
	int val; // if type == OPERAND
	char op; // if type == OPERATOR
}token;
enum state { NUMBER, OP, FINISH, ERROR, SPC, BRACK};
token gettoken(char *expr, int *reset) {
	static int i = 0;
	int no;
	char currchar;
	static enum state currstate = SPC;
	enum state nextstate;
	token t;
	if(*reset == 1) {
		currstate = SPC;
		*reset = 0;
		i = 0;
	}
	while(1) {
		currchar = expr[i];
		//printf("currstate: %s currchar: %c\n", states[currstate], currchar);
		switch(currstate) {
			case NUMBER:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						nextstate = NUMBER;
						no = no * 10 + (currchar - '0');
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case OP:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						t.type = OPERATOR;
						t.op = expr[i - 1];
						nextstate = NUMBER;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
					 	break;
				}
				break;
			case FINISH:
				t.type = END;
				return t;
				break;
			case ERROR:
				t.type = ERR;
				return t;
				break;
			case SPC:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						nextstate = NUMBER;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						i++;
						break;
					case '\0':
						nextstate = FINISH;
						break;
					case ' ':
						nextstate = SPC;
						i++;
						break;
					default: // anything else
						nextstate = ERROR;
						break;
				}
				currstate = nextstate;
				break;
		}
	}
}


int readline(char *line, int len) {
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n' && i < len - 1) 
		line[i++] = ch;
	line[i] = '\0';
	return i;
} 
int precedence(char op) {
	switch(op) {
		case '+': case '-':
			return 1;
			break;
		case '*': case '/':
			return 2;
			break;
		case '%':
			return 3;
			break;
		case '(': case ')':
			return 4;
		default:
			return 5;
			break;
	}
	return 5;
}
#include "stack.h"
#include "cstack.h"
char ctop(cstack *cs) {
	char ch = cpop(cs);
	cpush(cs, ch);
	return ch;
}
int infixeval(char *infix) {
	token t;
	int x, y, z, reset = 1;
	char prevop, c = 'a';
	stack s;
	cstack cs;		
	init(&s);
	cinit(&cs);
	while(1) {
		t = gettoken(infix, &reset);
		if(t.type == OPERAND) {
			if(!isfull(&s))
				push(&s, t.val);
			else {
				fprintf(stderr, "Too big an expression\n");
				return INT_MIN;
			}
		}
		else if(t.type == OPERATOR && cisempty(&cs)) {
			cpush(&cs, t.op);
		}	
		else if(t.type == OPERATOR && !cisempty(&cs)) {
				prevop = ctop(&cs);
				if(precedence(t.op) >= precedence(prevop))
					cpush(&cs, t.op);
				else {
					x = pop(&s);
					c = cpop(&cs);
					y = pop(&s);
					switch(c) {
					case '+':
						z = y + x;
						push(&s, z);
						break;
					case '-':
						z = y - x;
						push(&s, z);
						break;
					case '*':
						z = y * x;
						push(&s, z);
						break;
					case '/':
						z = y / x;
						push(&s, z);
						break;
					case '%':
						z = y % x;
						push(&s, z);
						break;	
					default :
						return z;
					}
					cpush(&cs, t.op);
				}
			
		}
		else if(t.type == BRACKET) {
			if(t.op == '(')
				cpush(&cs, t.op);
			if(t.op == ')') {
				while(1) {
					c = cpop(&cs);
					if(c == '(')
						break;
					x = pop(&s);
					y = pop(&s);
					switch(c) {
					case '+':
						z = y + x;
						push(&s, z);
						break;
					case '-':
						z = y - x;
						push(&s, z);
						break;
					case '*':
						z = y * x;
						push(&s, z);
						break;
					case '/':
						z = y / x;
						push(&s, z);
						break;
					case '%':
						z = y % x;
						push(&s, z);
						break;
					case '(':
						break;
					default:
						return z;	
					}
					push(&s, z);
				}	
			}
		}
		else {
			x = pop(&s);
			c = cpop(&cs);
			y = pop(&s);
			switch(c) {
			case '+':
				z = y + x;
				push(&s, z);
				break;
			case '-':
				z = y - x;
				push(&s, z);
				break;
			case '*':
				z = y * x;
				push(&s, z);
				break;
			case '/':
				z = y / x;
				push(&s, z);
				break;
			case '%':
				z = y % x;
				push(&s, z);
				break;	
			default :
				return z;
			}
			
		}		
	}
	z = pop(&s);
	return z;
}
int main() {
	char line[128];	
	int r, reset = 1;
	token t;
	while(readline(line, 128)) {
		r = infixeval(line);
		if(r != INT_MIN)
			printf("%d", r);
		else 
			fprintf(stderr, "Wrong Expression\n");
	}
	return 0;
}
