#include<stdio.h>

int is_even(int n) {
	return n % 2 == 0;
}

int abs(int n) {
	return n > 0 ? n : -n;
}

int pl(int n) {
	return !n ? 0 : n/abs(n);
}

float circle(float r) {
	return 3.14 * r * r;
}

int main() {
	printf("%d" , pl(-3));
}
