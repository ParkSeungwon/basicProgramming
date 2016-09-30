#include<stdio.h>

int main()
{
	double m, v;
	printf("질량을 입력하시오.");
	scanf("%lf", &m);
	printf("속도를 입력하시오.");
	scanf("%lf", &v);
	printf("운동에너지는 %f 입니다.\n", 0.5*m*v*v);
}
