#include<stdio.h>

int factorial(int n) {
	if(n == 1) return 1;
	return n * factorial(n-1);
}

int main()
{
	int n;
	printf("몇 번째까지 계산할까요?");
	scanf("%d", &n);
	double e = 0;
	for(int i=1; i<=n; i++) e += 1.0 / factorial(i);
	printf("오일러수는 %lf입니다.\n", e+1);
}
