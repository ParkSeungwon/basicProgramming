#include<stdio.h>
#include<ctype.h>

int main()
{
	int sum = 0;
	for(int i=3; i<=100; i+=3) sum += i;
	printf("%d\n", sum);

	int i=0;
	sum = 0;
	while(i <= 100) {
		sum += i;
		i += 3;
	}
	printf("%d\n", sum);

	sum = 0;
	i = 0;
	do {
		sum += i;
		i += 3;
	} while(i <= 100);
	printf("%d\n", sum);
}
