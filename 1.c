#include<stdio.h>
#include<ctype.h>

int main()
{
	char c;
	printf("문자를 입력하시오");
	scanf("%c", &c);
	c = tolower(c);
	switch(c) {
		case 'a': case 'e': case 'i': case 'o': case 'u': 
			printf("모음입니다.\n"); 
			break;
		default: printf("자음입니다.\n");
	}
}
