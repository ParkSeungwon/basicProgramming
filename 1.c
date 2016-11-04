#include<stdio.h>
#include<ctype.h>

int get_tax(int income) {
	int over = income - 10000000;
	if(over < 0) over = 0;
	int lower = income % 10000000;
	return over * 0.08 + lower * 0.1;
}

int main()
{
	int income;
	printf("수입을 입력하세요. ");
	scanf("%d", &income);
	printf("당신의 세금은 %d입니다.", get_tax(income));
}
