#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Arr {
	int *pBase;
	int cnt;
	int length;
};

//初始化数组
void init(struct Arr* pArr);
//设置数组长度
short setArrLength(struct Arr* pArr, int length);
//为数组追加一个数据
short appendArrItem(struct Arr* pArr, int value);
//为数组修改一个数据
short modifyArrItem(struct Arr* pArr, int value, short index);
//为数组插入一个数据
short insertArrItem(struct Arr* pArr, int value, short index);
//遍历数组
void showArr(struct Arr* pArr);

int main(void) {
	struct Arr arr;
	init(&arr);
	setArrLength(&arr, 4);
	appendArrItem(&arr, 1);
	appendArrItem(&arr, 7);
	//appendArrItem(&arr, 4);
	insertArrItem(&arr, 100, 3);
//	setArrLength(&arr,10);
	showArr(&arr);
	printf("\n\n\n\n");
  return 0;
}

void init(struct Arr* pArr) {
	pArr->pBase=NULL;
	pArr->cnt=0;
	pArr->length=0;
}
short setArrLength(struct Arr* pArr, int length) {
	if(pArr->pBase != NULL) {
		free(pArr->pBase);
		pArr->length=0;
		pArr->cnt=0;
	}
	pArr->pBase=(int *)malloc(sizeof(int)*length);
	if(pArr->pBase==NULL) {
		printf("内存申请失败！");
		exit(-1);
	}
	pArr->length=length;
	pArr->cnt=0;
	return 1;
}
short appendArrItem(struct Arr* pArr, int value) {
	if(pArr->cnt==pArr->length)
		return 0;
	pArr->pBase[pArr->cnt]=value;
	pArr->cnt++;
	return 1;
}
short modifyArrItem(struct Arr* pArr, int value, short index) {
	if(index>=pArr->length-1)
		return 0;
	pArr->pBase[index]=value;
	return 1;
}
short insertArrItem(struct Arr* pArr, int value, short index) {
	int i=pArr->cnt-1;
	if(pArr->cnt >= pArr->length || index<0 || index>=pArr->cnt)
		return 0;
	for(; i>=index; i--)
		pArr->pBase[i+1]=pArr->pBase[i];
	pArr->pBase[index]=value;
	pArr->cnt++;
	return 1;
}
void showArr(struct Arr* pArr) {
	int i=0;
	for(; i<pArr->cnt; i++)
		printf("%d ", pArr->pBase[i]);
	printf("\n");
}





















