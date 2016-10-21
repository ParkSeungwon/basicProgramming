#include<stdio.h>

int main()
{
	float f;
	int n = 0;
	float sum = 1;
	printf("실수의 값을 입력하시오.");
	scanf("%f", &f);
	printf("거듭제곱 횟수를 입력하시오.");
	scanf("%d", &n);
	for(int i=0; i<n; i++) sum *= f;
	printf("결과값은 %f입니다.\n", sum);
}

