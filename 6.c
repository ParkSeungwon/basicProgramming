#include<stdio.h>

int is_reap(int y) {
	if(y % 400 == 0) return 1;
	if(y % 100 == 0) return 0;
	if(y % 4 == 0) return 1;
	return 0;
}

int main()
{
	int y;
	printf("연도를 입력하시오.");
	scanf("%d", &y);
	printf("%d년은 %d일입니다.", y, 365+is_reap(y));
}

