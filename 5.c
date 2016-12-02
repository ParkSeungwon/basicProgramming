#include<stdio.h>

int main() {
	const char *p = "cheapest place in the world!";
	for(char *r = p; *r; r++) {
		for(char *q = r; *q; q++) printf("%c", *q);
		for(char *s = p; s != r; s++) printf("%c", *s);
		printf("\n");
		sleep(1);
	}
}



