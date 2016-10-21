#include<stdio.h>
int main()
{
	int n;
	printf("정수를 입력하시오.");
	scanf("%d", &n);
	if(n < 0) printf("오류. 음수입니다.");
	else {
		do {
			printf("%d", n%10);
			n /= 10;
		} while(n>0);
	}
}

