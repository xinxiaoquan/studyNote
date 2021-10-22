#include <stdio.h>
#include <malloc.h>

//链表节点
typedef struct Node {
	//数据域
	int data;
	//指针域
	struct Node * pNext;
}NODE, *PNODE;

//创建非循环单链表，返回首节点地址
PNODE create(void);
//遍历链表
void show(PNODE pHead);
//判断链表是否为空
int isEmpty(PNODE pHead);
//链表排序 type为0就是升序，type为1就是降序
void sort(PNODE pHead, int type);
//链表插入节点
void insert(PNODE pHead, int data, int pos);
//删除节点
int del(PNODE pHead, int pos);

int main(void) {
	PNODE pHead=create();
	show(pHead);
	printf("删除的数据%d\n", del(pHead, 100));
	show(pHead);
	return 0;
}

PNODE create(void) {
	PNODE pNode,pHead, pEnd;
	int i, len, val;
	pHead=(PNODE)malloc(sizeof(NODE));
	pHead->pNext=NULL;
	pEnd=pHead;
	printf("输入链表的长度：");
	scanf("%d", &len);
	for(i=0;i<len;i++) {
		pNode=(PNODE)malloc(sizeof(NODE));
		printf("输入%d项数据：", i+1);
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
	printf("链表的遍历结果：");
	if(isEmpty(pHead))
		printf("（空）");
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











