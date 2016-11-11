#include<stdio.h>
#include<ctype.h>

int add(int a, int b) { 
	static int count = 0;
	count++;
	printf("덧셈은 총 %d번 호출되었습니다.\n", count);
	printf("연산 결과 : %d\n", a+b);
	return a+b;
}
int sub(int a, int b) { 
	static int count = 0;
	count++;
	printf("뺄셈은 총 %d번 호출되었습니다.\n", count);
	printf("연산 결과 : %d\n", a-b);
	return a-b;
}
int mul(int a, int b) { 
	static int count = 0;
	count++;
	printf("곱셈은 총 %d번 호출되었습니다.\n", count);
	printf("연산 결과 : %d\n", a*b);
	return a*b;
}
int div(int a, int b) { 
	static int count = 0;
	count++;
	printf("나눗셈은 총 %d번 호출되었습니다.\n", count);
	printf("연산 결과 : %d\n", a/b);
	return a/b;
}

int main()
{
	int a, b;
	char c;
	int end = 0;
	while(!end) {
		printf("연산을 입력하시오.");
		scanf("%d%c%d", &a, &c, &b);
		switch(c) {
			case '+': add(a, b); break;
			case '-': sub(a, b);break;
			case '*': mul(a, b);break;
			case '/': div(a, b);break;
			default: end=1;
		}
	}
}
