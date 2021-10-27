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
//为数组删除一个数据
short delArrItem(struct Arr* pArr, short index, int* pVal);
//数组排序 method 1升序 0降序
short sortArr(struct Arr* pArr, short method);
//倒置数组
short reverseArr(struct Arr* pArr);
//遍历数组
void showArr(struct Arr* pArr);
//查找数组是否存在某个值
short findArrIndex(struct Arr* pArr, int value);
//交换两个整型变量的值
short swap(int* a, int* b);

int main(void) {
	struct Arr arr;
	int res=0;
	init(&arr);
	setArrLength(&arr, 6);
	appendArrItem(&arr, 1);
	appendArrItem(&arr, 4);
	appendArrItem(&arr, 7);
	appendArrItem(&arr, 2);
	appendArrItem(&arr, 3);
	appendArrItem(&arr, 9);
	sortArr(&arr, 0);
	//appendArrItem(&arr, 4);
	//reverseArr(&arr);
//	setArrLength(&arr,10);
	showArr(&arr);
	printf("%d\n", findArrIndex(&arr, 1));
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
short delArrItem(struct Arr* pArr, short index, int* pVal) {
	short i=index;
	if(index<0 || index>=pArr->cnt)
		return 0;
	*pVal=pArr->pBase[index];
	for(; i<=pArr->cnt-2; i++)
		pArr->pBase[i]=pArr->pBase[i+1];
	pArr->cnt--;
	return 1;
}
short reverseArr(struct Arr* pArr) {
	short i=0,j=pArr->cnt-1;
	int tmp;
	while(i<j) {
		swap(&(pArr->pBase[i]), &(pArr->pBase[j]));
		i++;
		j--;
	}
	return 1;
}
short sortArr(struct Arr* pArr, short method) {
	short i,j;
	int tmp;
	for(i=0; i<pArr->cnt; i++)
		for(j=i+1; j<pArr->cnt; j++) {
			if(method==1)
				if(pArr->pBase[i]>pArr->pBase[j])
					swap(&(pArr->pBase[i]), &(pArr->pBase[j]));
			if(method==0)
				if(pArr->pBase[i]<pArr->pBase[j])
					swap(&(pArr->pBase[i]), &(pArr->pBase[j]));
		}
	return 1;
}
void showArr(struct Arr* pArr) {
	int i=0;
	for(; i<pArr->cnt; i++)
		printf("%d ", pArr->pBase[i]);
	printf("\n");
}
short findArrIndex(struct Arr* pArr, int value) {
	short i=0;
	for(; i<pArr->cnt; i++) {
		if(pArr->pBase[i]==value)
			return i;
	}
	return -1;
}
short swap(int* a, int* b) {
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	return 1;
}
	



















