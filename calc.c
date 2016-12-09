#include<stdio.h>

int main()
{
	const char p[3][10] = {"fajsl", "fjdkla", "fdkjal"};
	int in[4][3][2];
	int(* pi)[3][2] = in;
	const char* q[] = {"fjsa", "fja", "fhuafahfui"};
	printf("%x, %x, %x", pi+1, in+1, pi);
}
