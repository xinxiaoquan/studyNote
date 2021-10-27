//µİ¹éÀÛ¼Ó1-100
#include <stdio.h>

//ÀÛ¼Óº¯Êı
int fn(int n);

int main(void) {
	printf("%d\n", fn(3));
}

int fn(int n) {
	if( n == 1 )
		return 1;
	return n+fn(n-1);
}