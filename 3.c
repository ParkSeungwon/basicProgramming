#include<stdio.h>
#include<stdlib.h>

int get_random() { 
	static int inited = 0;
	if(!inited) {
		inited = 1;
		printf("inited\n");
	}
}

int main()
{
	get_random();
	get_random();
	get_random();
	get_random();

}
