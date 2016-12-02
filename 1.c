#include<stdio.h>
#include<stdlib.h>

char b[50];
int c[50];
void check(char ch) {
	for(int i=0; i<50; i++) {
		if(b[i] == ch) {
			c[i]++;
			break;
		}
	}
}
int main()
{
	printf("문자열을 입력하세요");
	gets(b);
	for(int i=0; b[i]; i++) check(b[i]);
	for(int i=0; i<50; i++) if(c[i]) printf("%c : %d\n", b[i], c[i]);
}
