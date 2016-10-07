#include<stdio.h>

int main()
{
	int x, y;
	printf("x좌표를 입력하시오.");
	scanf("%d", &x);
	printf("y좌표를 입력하시오.");
	scanf("%d", &y);
	int z = x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
	printf("%d사분면\n", z);
}
