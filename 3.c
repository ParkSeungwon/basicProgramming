#include<stdio.h>

int main()
{
	char menu, garbage;
	int a, b, r, end = 0;
	do {
		printf("*******************\n");
		printf("A---------- Add\n");
		printf("S---------- Subtract\n");
		printf("M---------- Multiply\n");
		printf("D---------- Divide\n");
		printf("Q---------- Quit\n");
		printf("*******************\n");
		printf("연산을 선택하시오:");
		scanf("%c", &menu);
		printf("두 수를 공백으로 분리하여 입력하시오.:");
		scanf("%d %d", &a, &b);
		switch(menu) {
			case 'A': r = a + b; break; 
			case 'S': r = a - b; break;
			case 'M': r = a * b; break;
			case 'D': r = a / b; break;
			case 'Q': end = 1; break;
			default: printf("연산을 선택하시오."); break;
		}
		printf("%d\n", r);
	} while(!end);
}
