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
short pop(PSTACK stack, int * val);
//查看
void show(PSTACK stack);
//清空
void clear(PSTACK stack);

int main(void) {
	PSTACK stack;
	int val;
	stack=create();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	//clear(stack);
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

short pop(PSTACK stack, int * val) {
	PNODE top;
	if(stack->top == stack->bottom)
		return 0;
	top=stack->top;
	*val=top->data;
	stack->top=stack->top->pNext;
	free(top);
	return 1;
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

void clear(PSTACK stack) {
	/*
	实现方式1
	int val;
	while(pop(stack, &val)) {}
	*/
	PNODE p,q;
	p=stack->top;
	while(p != stack->bottom) {
		q=p->pNext;
		free(p);
		p=q;
	}
	stack->top=stack->bottom;
}




