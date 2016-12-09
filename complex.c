#include<stdbool.h>
#include<stdio.h>
#include<stdarg.h>
#include<signal.h>
#include<string.h>
typedef char str[30];

int vsum(int n, ...) {
	int sum = 0;
	va_list vl;
	va_start(vl, n);
	vprintf("%d, %d, %d, %d, %d\n", vl);
	va_start(vl, n);
	for(int i=0; i<n; i++) sum += va_arg(vl, int);
	va_end(vl);
	return sum;
}

void handler(int sig) {
	printf("error");
}
int main() {
	printf("%d is sum\n", vsum(5, 1,2,3,4,5));
	void(*prev)(int);
	prev = signal(SIGINT, handler);
	raise(SIGINT);
	str s = "This, is, a, test";
	char* p = strtok(s, ",\n");
	printf(p);
	while(p = strtok(NULL, ",\n")) printf(p);
	printf("\n%d\n", strlen(s));
}
