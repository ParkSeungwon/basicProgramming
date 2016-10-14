#include<stdio.h>

int main()
{
	int weight, height;
	printf("체중과 키를 입력하세요.");
	scanf("%d %d", &weight, &height);
	if(weight > (height - 100) * 0.9) printf("과체중입니다.\n");
	else printf("저체중입니다..\n");
}
