#include<stdio.h>

int main()
{
	double a, b;
	printf("두 개의 실수를 입력하시오.\n");
	scanf("%lf%lf", &a, &b);
	printf("합 : %lf\n차 : %lf\n곱 : %lf\n몫 : %lf\n", a+b, a-b, a*b, a/b);
}
