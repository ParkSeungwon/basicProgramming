#include<stdio.h>

int array_sum(int *A, int size) {
	int i, sum=0;
	for(i=0; i<size; i++) {
		sum += A[i];
	}
	return sum;
}

int main() {
	int A[10] = {234, 231, 255, 300, 400, 424, 232, 332, 200, 190};
	printf("직원들의 월급의 합은 %d입니다.\n", array_sum(A, 10));
}
