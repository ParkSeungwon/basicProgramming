#include<stdio.h>

int main()
{
	float f;
	printf("값을 입력하시오.");
	scanf("%f", &f);
	printf("실수형식으로는 %f이고\n 지수형식으로는 %e입니다.\n", f, f);
}
