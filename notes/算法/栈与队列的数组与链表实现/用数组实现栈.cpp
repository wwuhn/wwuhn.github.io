#include <stdio.h>
#include <stdlib.h>

#define RogueValue -9999
#define MaxStack 10

typedef struct stack{
	int top;
	int ST[MaxStack];
}StackType, *Stack;

Stack initStack();
int empty(Stack);
void push(Stack, int);
int pop(Stack);
int top(Stack);

Stack initStack() {
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = -1;
	return sp;
}

int empty(Stack S) {
	return (S -> top == -1);
}

void push(Stack S, int n) {
	if (S -> top == MaxStack - 1) {
		printf("\nStack Overflow\n");
		exit(1);
	}
	++(S -> top);
	S -> ST[S -> top]= n;
}

int pop(Stack S) {
	if (empty(S)) return RogueValue;
	int hold = S -> ST[S -> top];
	--(S -> top);
	return hold;
}

int top(Stack S) {
	if (empty(S)) return RogueValue;
	int hold = S -> ST[S -> top];
	return hold;
}

int main() 
{
	int n;
	Stack S = initStack();
	printf("Enter some integers, ending with 0\n");
	scanf("%d", &n);
	while (n != 0) {
		push(S, n);
		scanf("%d", &n);
	}
	printf("%d\n",top(S));
	printf("Numbers in reverse order\n");
	
	while (!empty(S))
		printf("%d ", pop(S));
	system("pause");
	printf("\n");
} //end main


/*
Enter some integers, ending with 0
2 6 9 12 3 0
Numbers in reverse order
3 12 9 6 2
*/