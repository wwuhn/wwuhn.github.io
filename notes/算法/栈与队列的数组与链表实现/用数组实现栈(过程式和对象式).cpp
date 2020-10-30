#include <stdio.h>
#include <stdlib.h>

#define RogueValue -9999
#define MaxStack 10

class Stack{
	int top;
	int ST[MaxStack];
public:
	Stack();
	int empty();
	void push(int);
	int pop();
	int getTop();
};

Stack::Stack() {
	top = -1;
}

int Stack::empty() {
	return (top == -1);
}

void Stack::push(int n) {
	if (top == MaxStack - 1) {
		printf("\nStack Overflow\n");
		exit(1);
	}
	++(top);
	ST[top]= n;
}

int Stack::pop() {
	if (empty()) return RogueValue;
	int hold = ST[top];
	--(top);
	return hold;
}

int Stack::getTop() {
	if (empty()) return RogueValue;
	int hold = ST[top];
	return hold;
}

int main() 
{
	int n;
	Stack s;
	printf("Enter some integers, ending with 0\n");
	scanf("%d", &n);
	while (n != 0) {
		s.push(n);
		scanf("%d", &n);
	}

	printf("Numbers in reverse order\n");
	
	while (!s.empty())
		printf("%d ", s.pop());
	system("pause");
	printf("\n");
} 


/*
Enter some integers, ending with 0
2 6 9 12 3 0
Numbers in reverse order
3 12 9 6 2
*/