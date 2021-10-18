#include <stdio.h>
#include <malloc.h>

//����ڵ�
typedef struct Node {
	//������
	int data;
	//ָ����
	struct Node * pNext;
}NODE, *PNODE;

PNODE createList(void);
void traversal(PNODE pNode);

int main(void) {
	PNODE pNode=createList();
	traversal(pNode);
	return 0;
}

//������ѭ�������������׽ڵ��ַ
PNODE createList(void) {
	PNODE pNode, lastPNode;
	int i, len, val;
	lastPNode=NULL;
	printf("��������ĳ��ȣ�");
	scanf("%d", &len);
	for(i=0;i<len;i++) {
		pNode=(PNODE)malloc(sizeof(NODE));
		printf("����%d�����ݣ�", i+1);
		scanf("%d", &val);
		pNode->data=val;
		pNode->pNext=lastPNode;
		lastPNode=pNode;
	}
	return pNode;
}

//��������
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
















