#include <stdio.h>

int main() 
{
	char b[8];
	short* pd;
	int* pi;
	pd = (short*)b;
	pi = (int*)b;
	*pi = 12332422;
	printf("%d\n", *pi);
	*pd = 314;
	printf("%d\n", *pi);
}

