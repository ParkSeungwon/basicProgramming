#include<stdio.h>

int lcm(int x, int y) {
	if(!y) return x;
	return lcm(x, x % y);
}

int gcd(int x, int y) {
	for(int i=1; ; i++) if((x * i) % y == 0) return x * i; 
}

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd) {
	*p_lcm = lcm(x, y);
	*p_gcd = gcd(x, y);
}

int main() {
	int x = 88, y = 240, l, g;
	get_lcm_gcd(x, y, &l ,&g);
	printf("%d와 %d의 최대공약수는 %d이고, 최소공배수는 %d입니다.\n", x, y, l, g);
}
