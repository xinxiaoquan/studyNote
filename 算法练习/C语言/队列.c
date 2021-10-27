//使用数组实现的静态队列（循环队列）

#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	int front;
	int rear;
	int *pArr;
	int arrLen;
}QUEUE, * PQUEUE;

//创建队列
PQUEUE create(int len);
//入队
void enQueue(PQUEUE pQ, int val);
//出队
int outQueue(PQUEUE pQ);
//遍历队列
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
	//	printf("队列已满！\n");
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
		printf("队列是空的！");
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