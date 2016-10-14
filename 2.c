#include<stdio.h>

int main()
{
	int a, b;
	printf("두 개의 정수를 입력하시오.");
	scanf("%d %d", &a, &b);
	if(a % b == 0) printf("약수입니다.\n");
	else printf("약수가 아닙니다.\n");
}
