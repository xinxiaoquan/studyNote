//�ݹ�׳�1-100
#include <stdio.h>

//�׳˺���
int fn(int n);

int main(void) {
	printf("%ld\n", fn(20));
}

int fn(int n) {
	if( n == 1 )
		return 1;
	return n*fn(n-1);
}