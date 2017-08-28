#include<stdio.h>
void getinp(char *inp, int siz)
{
	puts("Input value: ");
	fgets(inp, siz, stdin);
	printf("buffer3 getinp read %s\n", inp);
}

void display(char *val)
{
	char tmp[16];
	sprintf(tmp, "read val: %s\n", val);
	puts(tmp);
}

int main(int argc, char *argv[])
{
	char buf[16];
	getinp(buf, sizeof(buf));
	display(buf);
	printf("buffer3 done\n");
}
