#include<stdio.h>
#include<stdbool.h>
void hello(char* name)
{
	char inp[16];
	printf("enter value for %s: ", name);
	gets(inp);
	printf("Hello your %s is %s\n", name, inp);
}

int main()
{
	hello("Park");
}

	
