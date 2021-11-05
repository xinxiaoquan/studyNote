#include <stdio.h>

typedef struct Node {
	char data;
	struct Node * pLNode;
	struct Node * pRNode;
}NODE, * PNODE;

//静态创建一个二叉树(返回根节点地址)
PNODE create(void);
//创建一个二叉树节点
PNODE getNode(char);
//先序遍历
void preShow(PNODE);
//中序遍历
void midShow(PNODE);
//后序遍历
void backShow(PNODE);

int main(void) {
	PNODE tree = create();
	printf("链式二叉树：\n");
	printf("先序遍历：");
	preShow(tree);
	printf("\n");
	printf("中序遍历：");
	midShow(tree);
	printf("\n");
	printf("后序遍历：");
	backShow(tree);
	printf("\n\n");
	return 0;
}

PNODE create(void) {
	PNODE pA = getNode('A');
	PNODE pB = getNode('B');
	PNODE pC = getNode('C');
	PNODE pD = getNode('D');
	PNODE pE = getNode('E');

	pA->pLNode = pB;
	pA->pRNode = pC;
	pC->pLNode = pD;
	pD->pRNode = pE;

	return pA;
}

PNODE getNode(char c) {
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p->data = c;
	p->pLNode = NULL;
	p->pRNode = NULL;
	return p;
}

void preShow(PNODE tree) {
	if(tree == NULL)
		return;
	printf("%c ", tree->data);
	preShow(tree->pLNode);
	preShow(tree->pRNode);
}

void midShow(PNODE tree) {
	if(tree == NULL)
		return;
	midShow(tree->pLNode);
	printf("%c ", tree->data);
	midShow(tree->pRNode);
}

void backShow(PNODE tree) {
	if(tree == NULL)
		return;
	backShow(tree->pLNode);
	backShow(tree->pRNode);
	printf("%c ", tree->data);
}