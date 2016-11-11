#include<stdio.h>

int get_tri_number(int n) {
	if(n == 1) return 1;
	return get_tri_number(n-1) + n;
}

int main()
{
	for(int i=1; i<10; i++) 
		printf("%d번째 삼각수는 %d입니다.\n", i, get_tri_number(i));
}

