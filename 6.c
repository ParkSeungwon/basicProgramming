#include<stdio.h>

void array_copy (int *A , int *B , int size) {
	int i ;
	for(i= 0 ; i < size ; i++) {
		B[i] = A[i];
	}
}

int main()
{
	int A[10] = {4, 4, 3, 2, 1, 4, 4, 3, 3, 2};
	int B[10];
	array_copy(A, B, 10);
	for(int i=0; i<10; i++) printf("%d ", B[i]);
}

