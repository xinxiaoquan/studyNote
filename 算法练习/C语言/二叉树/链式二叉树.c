#include <stdio.h>

typedef struct Node {
	char data;
	struct Node * pLNode;
	struct Node * pRNode;
}NODE, * PNODE;

//��̬����һ��������(���ظ��ڵ��ַ)
PNODE create(void);
//����һ���������ڵ�
PNODE getNode(char);
//�������
void preShow(PNODE);
//�������
void midShow(PNODE);
//�������
void backShow(PNODE);

int main(void) {
	PNODE tree = create();
	printf("��ʽ��������\n");
	printf("���������");
	preShow(tree);
	printf("\n");
	printf("���������");
	midShow(tree);
	printf("\n");
	printf("���������");
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