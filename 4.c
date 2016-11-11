#include<stdio.h>
#include<stdlib.h>

float f(int n) {
	if(n == 1) return 1;
	else return f(n-1) + (float)1/n;
}

int main(int c, char** v) {
	printf("%f", f(atoi(v[1])));
}
