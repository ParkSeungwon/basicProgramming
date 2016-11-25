#include<stdio.h>

void get_sum_diff(int x, int y, int*p_sum, int*p_diff) {
	*p_sum = x + y;
	*p_diff = x - y;
}

int main()
{
	int x = 5;
	int y = 3;
	int sum, diff;
	get_sum_diff(x, y, &sum, &diff);
	printf("sum is %d, diff is %d\n", sum, diff);
}
