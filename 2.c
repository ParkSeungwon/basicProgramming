#include<stdio.h>

int main()
{
	int f;
	printf("값을 입력하시오.");
	scanf("%d", &f);
	
	printf("8진수로는 %o이고,\n 10진수로는 %d이고,\n 16진수로는 %x입니다..\n", f, f, f);
}
