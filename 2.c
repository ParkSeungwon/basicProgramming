#include<stdio.h>

int main()
{
	for(int i=1; i<=7; i++) {
		for(int j=0; j<7-i; j++) printf(" ");
		for(int k=0; k<i; k++) printf("*");
		printf("\n");
	}
}
