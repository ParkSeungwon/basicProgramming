#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int sum = 0;
	int ar[3][5] = {12,56,32,16,98, 99,56,34,41,3, 65,3,87,78,21};
	for(int y=0; y<3; y++) for(int x=0; x<5; x++) {
		sum += ar[y][x];
		if(x == 4) {
			printf("%d행의 합계는 %d입니다.\n", y+1, sum);
			sum = 0;
		}
	}
	sum = 0;
	for(int x=0; x<5; x++) for(int y=0; y<3; y++) {
		sum += ar[y][x];
		if(y == 2) {
			printf("%d열의 합계는 %d입니다.\n", x+1, sum);
			sum = 0;
		}
	}
}
