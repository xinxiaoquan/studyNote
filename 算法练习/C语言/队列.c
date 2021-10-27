//ʹ������ʵ�ֵľ�̬���У�ѭ�����У�

#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	int front;
	int rear;
	int *pArr;
	int arrLen;
}QUEUE, * PQUEUE;

//��������
PQUEUE create(int len);
//���
void enQueue(PQUEUE pQ, int val);
//����
int outQueue(PQUEUE pQ);
//��������
void show(PQUEUE pQ);

int main(void) {
	PQUEUE pQ = create(10);
	enQueue(pQ, 1);
	enQueue(pQ, 2);
	enQueue(pQ, 3);

	printf("%d ", outQueue(pQ));
	printf("%d ", outQueue(pQ));

//	show(pQ);
}

PQUEUE create(int len) {
	PQUEUE pQ;
	len=len+1;
	pQ = (PQUEUE)(malloc(sizeof(QUEUE)));
	pQ->arrLen = len;
	pQ->pArr = (int*)(malloc(sizeof(int)*pQ->arrLen));
	pQ->front = 0;
	pQ->rear = 0;
	return pQ;
}

void enQueue(PQUEUE pQ, int val) {
	int rearNext;
	rearNext = (pQ->rear+1)%pQ->arrLen;
	if ( rearNext == pQ->front) {
	//	printf("����������\n");
		return;
	}
	pQ->pArr[pQ->rear] = val;
	pQ->rear = rearNext;
}

void show(PQUEUE pQ) {
	int pIndex;
	int rearNext;
	rearNext = (pQ->rear+1)%pQ->arrLen;
	if( pQ->front == pQ->rear ) {
		printf("�����ǿյģ�");
		return;
	}
	pIndex = pQ->front;
	while ( pIndex != pQ->rear ) {
		printf("%d ", pQ->pArr[pIndex]);
		pIndex = (pIndex+1)%pQ->arrLen;
	}
	printf("\n");
}

int outQueue(PQUEUE pQ) {
	int val;
	if ( pQ->front == pQ->rear )
		return -1;
	val = pQ->pArr[pQ->front];
	pQ->front = (pQ->front+1)%pQ->arrLen;
	return val;
}