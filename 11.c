#include<stdio.h>

void merge(int* A, int* B, int* C, int size) {
	int a=0, b=0;
	for(int i=0; i<2*size; i++) {
		if(a == size) C[i] = B[b++];
		else if(b == size) C[i] = A[a++];
		else C[i] = A[a] < B[b] ? A[a++] : B[b++];
	}
}

int main() 
{
	int A[] = {2,5,7,8};
	int B[] = {1,3,4,6};
	int C[8];

	merge(A, B, C, 4);
	for(int i=0; i<8; i++) printf("%d ", C[i]);
}
