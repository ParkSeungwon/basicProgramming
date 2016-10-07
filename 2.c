#include<stdio.h>

int main()
{
	float f;
	printf("키를 입력하시오.(cm) : ");
	scanf("%f", &f);
	float inch = f / 2.54;
	int feet = inch / 12;
	inch -= feet * 12;
	printf("키는 %d 피트 %f 인치 입니다.\n", feet, inch);
}
