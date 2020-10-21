#include <stdlib.h>
#include <stdio.h>
typedef struct {
	char ch;
} StackData;
typedef struct node 
{
	StackData data;
	struct node *next;
} Node, *NodePtr;
typedef struct stackType {
	NodePtr top;
} StackType, *Stack;
Stack initStack() {
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = NULL;
	return sp;
}
int empty(Stack S) {
	return (S -> top == NULL);
}
void push(Stack S, StackData d) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> data = d;
	np -> next = S -> top;
	S -> top = np;
}
StackData pop(Stack S) {
	if (empty(S)) {
		printf("\nAttempt to pop an empty stack\n");
		exit(1);
	}
	StackData hold = S -> top -> data;
	NodePtr temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}

int main() 
{
	StackData temp;
	char c;
	Stack S = initStack();
	printf("Type some data and press Enter\n");
	while ((c = getchar()) != '\n') {
		temp.ch = c;
		push(S, temp);
	}
	printf("\nData in reverse order\n");
	while (!empty(S))
		putchar(pop(S).ch);
	
	putchar('\n');
	system("pause");
} //end main

/*
Type some data and press Enter
abcdef

Data in reverse order
fedcba
*/
