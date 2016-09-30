#include<stdio.h>

int main()
{
	int x=10,y=20;
	printf("x=%d, y=%d\n", x, y);
	int tmp = x;
	x = y;
	y = tmp;
	printf("x=%d, y=%d\n", x, y);
}
