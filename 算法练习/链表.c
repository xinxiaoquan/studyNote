#include <stdio.h>
#include <malloc.h>

//����ڵ�
typedef struct Node {
	//������
	int data;
	//ָ����
	struct Node * pNext;
}NODE, *PNODE;

//������ѭ�������������׽ڵ��ַ
PNODE create(void);
//��������
void show(PNODE pHead);
//�ж������Ƿ�Ϊ��
int isEmpty(PNODE pHead);
//�������� typeΪ0��������typeΪ1���ǽ���
void sort(PNODE pHead, int type);
//�������ڵ�
void insert(PNODE pHead, int data, int pos);
//ɾ���ڵ�
int del(PNODE pHead, int pos);

int main(void) {
	PNODE pHead=create();
	show(pHead);
	printf("ɾ��������%d\n", del(pHead, 100));
	show(pHead);
	return 0;
}

PNODE create(void) {
	PNODE pNode,pHead, pEnd;
	int i, len, val;
	pHead=(PNODE)malloc(sizeof(NODE));
	pHead->pNext=NULL;
	pEnd=pHead;
	printf("��������ĳ��ȣ�");
	scanf("%d", &len);
	for(i=0;i<len;i++) {
		pNode=(PNODE)malloc(sizeof(NODE));
		printf("����%d�����ݣ�", i+1);
		scanf("%d", &val);
		pNode->data=val;
		pNode->pNext=NULL;
		pEnd->pNext=pNode;
		pEnd=pNode;
	}
	return pHead;
}

void show(PNODE pHead) {
	PNODE pNode;
	pNode=pHead->pNext;
	printf("����ı��������");
	if(isEmpty(pHead))
		printf("���գ�");
	else while(1) {
		printf("%d ", pNode->data);
		if(pNode->pNext == NULL)
			break;
		pNode=pNode->pNext;
	}
	printf("\n");
	return;
}

int isEmpty(PNODE pHead) {
	if(pHead->pNext == NULL)
		return 1;
	return 0;
}

void sort(PNODE pHead, int type) {
	PNODE p,q;
	int tmp;
	for (p=pHead->pNext; p!=NULL; p=p->pNext) {
		for (q=p->pNext; q!=NULL; q=q->pNext) {
			if (p->data > q->data && type != 0)
				continue;
			if (p->data < q->data && type != 1)
				continue;
			tmp = p->data;
			p->data = q->data;
			q->data = tmp;
		}
	}
	return;
}

void insert(PNODE pHead, int data, int pos) {
	int nowPos=1;
	PNODE pNode=pHead, pNew;
	while(nowPos<pos) {
		nowPos++;
		if(pNode->pNext == NULL)
			break;
		pNode=pNode->pNext;
	}
	pNew=(PNODE)malloc(sizeof(NODE));
	pNew->data=data;
	pNew->pNext=pNode->pNext;
	pNode->pNext=pNew;
}

int del(PNODE pHead, int pos) {
	int nowPos=1, val;
	PNODE pNode=pHead, pTar;
	if(pos < nowPos)
		return -1;
	else while(nowPos < pos) {
		if(pNode == NULL)
			return -1;
		nowPos++;
		pNode=pNode->pNext;
	}
	pTar=pNode->pNext;
	pNode->pNext=pTar->pNext;
	val=pTar->data;
	free(pTar);
	return val;
}











