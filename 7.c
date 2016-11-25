#include<stdio.h>

void array_add(int *A, int *B, int *C, int size) {
	int i;
	for(i=0; i<size; i++) {
		C[i] = A[i] + B[i];
	}
}

int main() {
	int A[10] = {4, 4, 3, 2, 1, 4, 4, 3, 3, 2};
	int B[10] = {4, 5, 3, 7, 1, 6, 2, 3, 3, 2};
	int C[10]; 

	array_add(A, B, C, 10);
	for(int i=0; i<10; i++) printf("%d ", C[i]);
}
