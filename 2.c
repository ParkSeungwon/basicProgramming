#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int get_response(char* prompt)
{
	char b[50];
	printf(prompt);
	gets(b);
	for(int i=0; i<50; i++) b[i] = tolower(b[i]);
	if(!strcmp(b , "yes") || !strcmp(b, "ok")) return 1;
	else if(!strcmp(b, "no")) return 0;
	else return -1;
}

int main() {
	if(get_response("답변을 입력하세요.yes/no")) printf("긍정\n");
	else printf("부정\n");
}
