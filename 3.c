#include<stdio.h>
#include<stdlib.h>

int main()
{
	char b[50];
	printf("문자열을 입력하시오.");
	gets(b);
	int i=0;
	for(; b[i]; i++);
	for(int j=i; j>=0; j--) printf("%c", b[j]);
}
