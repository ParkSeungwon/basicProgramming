#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c[4];
	for(int i=0; i<4; i++) {
		printf("%d번째 문자를 입력하시오.", i+1);
		c[i] = getchar();
		getchar();
	}

	int r = 0;
	for(int i=0; i<4; i++) {
		int k = c[i];
		k <<= 24 - 8 * i;
		r |= k;
	}
	printf("결과값 : %x\n", r);
}

