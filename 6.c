#include<stdio.h>

int main()
{
	int x, y;
	printf("좌표(x,y) : ");
	scanf("%d %d", &x, &y);
	int r = x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
	printf("%d사분면입니다.\n", r);
}

