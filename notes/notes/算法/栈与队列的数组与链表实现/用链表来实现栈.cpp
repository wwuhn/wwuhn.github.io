#include <stdio.h>
#include <stdlib.h>

#define RogueValue -9999

typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;

typedef struct stackType {
	NodePtr top;
} StackType, *Stack;

Stack initStack();
int empty(Stack);
void push(Stack, int);
int pop(Stack);
int top(Stack S);

Stack initStack() 
{
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = NULL;
	return sp;
}

int empty(Stack S) 
{
	return (S -> top == NULL);
}

void push(Stack S, int n) 
{
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> num = n;
	np -> next = S -> top;	// 新节点指针域指向栈顶
	S -> top = np;			// 移动栈顶节点指向新节点
}

int pop(Stack S) 
{
	if (empty(S)) 
		return RogueValue;
	int hold = S -> top -> num;
	NodePtr temp = S -> top;		// 获取栈顶节点指针，待释放
	S -> top = S -> top -> next;	// 栈顶节点指向下一个节点
	free(temp);
	return hold;
}

int top(Stack S) 
{
	if (empty(S)) 
		return RogueValue;
	int hold = S -> top -> num;
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
	printf("\n");
	system("pause");
}
/*
Enter some integers, ending with 0
4 6 8 12 3 0
3
Numbers in reverse order
3 12 8 6 4
*/