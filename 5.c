#include<stdio.h>

int main() {
	int n;
	printf("2진수로 변환할 10진수를 입력하세요.");
	scanf("%d", &n);
	int binary[23] = {0,};
	int i;
	for (i=0;i<23&&n>0;i++) {
		binary[i] = n % 2 ;
		n = n / 2 ;
	}
	for(i=22; !binary[i]; i--);
	for(; i>=0; i--) printf("%d", binary[i]);
	printf("\n");
}



