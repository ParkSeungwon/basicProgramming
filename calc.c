#include<stdio.h>

int main()
{
	int a, b, r;
	char op;
	printf("계산식을 숫자 연산자 숫자의 형태로 입력하세요.\n");
	scanf("%d %c %d", &a, &op, &b);
	switch(op) {
		case '+': r = a + b; break;
		case '-': r = a - b; break;
		case '*': r = a * b; break;
		case '/': r = a / b; break;
		default: printf("지원되지 않는 연산자입니다.\n");
	}
	printf("%d %c %d = %d\n", a, op, b, r);
}
