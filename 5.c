#include<stdio.h>

int main()
{
	int sum = 0;
	int prev;
	for(int i=1; ; i++) {
		prev = sum;
		sum += i;
		if(sum > 10000) {
			printf("1부터 %d까지의 합이 %d입니다.\n", i-1, prev);
			break;
		}
	}
}
