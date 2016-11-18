#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ar[3][11];
	for(int i=1; i<11; i++) {
		ar[0][i] = i;
		ar[1][i] = i * i;
		ar[2][i] = i * i * i;
	}

	for(int y=0; y<3; y++) {
		for(int x=1; x<11; x++) printf("%d ", ar[y][x]);
		printf("\n");
	}

	printf("세제곱값을 입력하세요.");
	int n, k;
	scanf("%d", &k);
	for(int i=1; i<11; i++) if(k == ar[2][i]) n = ar[0][i];
	printf("%d의 세제곱근은 %d입니다.\n", k, n);

}
