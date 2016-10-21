#include<stdio.h>
int main()
{
	int a, b, c, r;
	printf("세 개의 정수를 입력하세요.\n");
	scanf("%d %d %d", &a, &b, &c);
	if(a < b) r = a;
	else r = b;
	if(r > c) r = c;
	printf("가장 작은 정수는 %d입니다.\n", r);
}
