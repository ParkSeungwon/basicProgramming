#include<stdio.h>

int main()
{
	int a;
	printf("정수를 입력하시오.");
	scanf("%d", &a);
	a = ~a;
	a++;
	printf("2의 보수는 %d입니다. \n", a);
}
