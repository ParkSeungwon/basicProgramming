#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() {
	char b[80], f[20], r[20], tmp[20];
	printf("문자열을 입력하시오.");
	fgets(b, 80, stdin);
	printf("찾을 문자열:");
	scanf("%s", f);
	printf("바꿀 문자열:");
	scanf("%s", r);
	printf("결과:");
	int lf = strlen(f);
	char* p = strstr(b, f);
	strcpy(tmp, p+lf);
	strcpy(p, r);
	strcat(p, tmp);
	printf(b);
}



