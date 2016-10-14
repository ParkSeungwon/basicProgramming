#include<stdio.h>
#include<ctype.h>
int main()
{
	printf("문자를 입력하시오.");
	char c;
	scanf("%c", &c);
	c = tolower(c);
	switch(c) {
		case 'r': printf("Rectangle"); break;
		case 't': printf("Triangle"); break;
		case 'c': printf("Circle"); break;
		default: printf("Unknown"); 
	}
	printf("\n");
}

