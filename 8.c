#include<stdio.h>

void show_digit(int n) {
	printf("%d ", n%10);
	if(n >9) show_digit(n/10);
}

int main() {
	show_digit(2346);
}
