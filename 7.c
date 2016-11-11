#include<stdio.h>

int nCr(int n, int r) {
	if(r == 0 || r == n) return 1;
	return nCr(n-1, r-1) + nCr(n-1, r);
}
int factorial(int n) {
	int r = 1;
	for(int i=1; i<=n; i++) r *= i;
	return r;
}

long nCk(int n, int k) {
	long r = 1;
	for(int i=k+1; i<=n; i++) r *= i;
	for(int i=1; i<=n-k; i++) r /= i;
	return r;
}

int main() {
	printf("%d\n", nCr(10, 3));
	printf("%d\n", nCk(10, 3));
}
