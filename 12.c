#include<stdio.h>

int main()
{
	int i=1, sum=0, prev;
	while(sum < 10000) {
		prev = sum; 
		sum+= i;
		i++;
	}
	printf("%d %d", prev, i-2);
}

