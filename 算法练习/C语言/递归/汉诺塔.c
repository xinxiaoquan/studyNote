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
		�����1������
			ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
		����
			�Ƚ�A�����ϵ�n-1�����ӽ���C�ƶ���B
			ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
			���B�����ϵ�n-1�����ӽ���A�ƶ���C
	*/
	if (n == 1)
	{
		printf("���[%d]��%c�ƶ���%c\n",n,A,C);
		return;
	}
	hnt(n-1,A,C,B);
	printf("���[%d]��%c�ƶ���%c\n",n,A,C);
	hnt(n-1,B,A,C);
}








