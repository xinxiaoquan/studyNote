//链表实现的 动态栈
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Stack {
	PNODE top;
	PNODE bottom;
}STACK, *PSTACK;

//创建一个栈
PSTACK create(void);
//入栈
void push(PSTACK stack, int data);
//出栈
int pop(PSTACK stack);
//查看
void show(PSTACK stack);

int main(void) {
	PSTACK stack;
	stack=create();
	push(stack, 123);
	show(stack);
	return 0;
}

PSTACK create(void) {
	PNODE pBottom;
	PSTACK stack;
	stack=(PSTACK)malloc(sizeof(STACK));
	pBottom=(PNODE)malloc(sizeof(NODE));
	pBottom->pNext=NULL;
	stack->top=pBottom;
	stack->bottom=pBottom;
	return stack;
}

void push(PSTACK stack, int data) {
	PNODE pNode;
	pNode=(PNODE)malloc(sizeof(NODE));
	pNode->data=data;
	pNode->pNext=stack->top;
	stack->top=pNode;
}

int pop(PSTACK stack) {
	PNODE top;
	int val;
	if(stack->top == stack->bottom)
		return -1;
	top=stack->top;
	val=top->data;
	stack->top=stack->top->pNext;
	free(top);
	return val;
}

void show(PSTACK stack) {
	PNODE pIndex;
	if(stack->top == stack->bottom) {
		printf("(空栈)\n");
		return;
	}
	pIndex=stack->top;
	while (pIndex != stack->bottom) {
		printf("%d ", pIndex->data);
		pIndex=pIndex->pNext;
	}
	printf("\n");
}