#include <stdio.h>

int main(void) {
	int i=1, res=1;
	for(; i<=5; i++)
		res = res*i;
	printf("%d\n", res);
}