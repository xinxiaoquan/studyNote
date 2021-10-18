#include <stdio.h>
#include <malloc.h>

//链表节点
typedef struct Node {
	//数据域
	int data;
	//指针域
	struct Node * pNext;
}NODE, *PNODE;

PNODE createList(void);
void traversal(PNODE pNode);

int main(void) {
	PNODE pNode=createList();
	traversal(pNode);
	return 0;
}

//创建非循环单链表，返回首节点地址
PNODE createList(void) {
	PNODE pNode, lastPNode;
	int i, len, val;
	lastPNode=NULL;
	printf("输入链表的长度：");
	scanf("%d", &len);
	for(i=0;i<len;i++) {
		pNode=(PNODE)malloc(sizeof(NODE));
		printf("输入%d项数据：", i+1);
		scanf("%d", &val);
		pNode->data=val;
		pNode->pNext=lastPNode;
		lastPNode=pNode;
	}
	return pNode;
}

//遍历链表
void traversal(PNODE pNode) {
	printf("\n");
	while(1) {
		printf("%d ", pNode->data);
		if(pNode->pNext == NULL)
			break;
		pNode=pNode->pNext;
	}
	printf("\n\n");
}
















