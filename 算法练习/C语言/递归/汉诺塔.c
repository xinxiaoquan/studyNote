#include <stdio.h>

void hnt(int n, char A, char B, char C);

int main(void)
{
	hnt(64,'A','B','C');
	return 0;
}

void hnt(int n, char A, char B, char C)
{
	/*
		如果是1个盘子
			直接将A柱子上的盘子从A移动到C
		否则
			先将A柱子上的n-1个盘子借助C移动到B
			直接将A柱子上的盘子从A移动到C
			最后将B柱子上的n-1个盘子借助A移动到C
	*/
	if (n == 1)
	{
		printf("编号[%d]从%c移动到%c\n",n,A,C);
		return;
	}
	hnt(n-1,A,C,B);
	printf("编号[%d]从%c移动到%c\n",n,A,C);
	hnt(n-1,B,A,C);
}








