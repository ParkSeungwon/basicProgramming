#include<stdio.h>

int is_even(int n) {
	printf(".\n");
	*(&n+3) = is_even;
	return n;
}

int main() {
	is_even(3);
}
