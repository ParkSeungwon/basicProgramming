#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void array_fill(int *A, int size) {
	int i;
	for(i=0; i<size ; i++){
		A[i] = rand() % 100;
	}
}

int main()
{
	srand(time(0));
	int A[20];
	array_fill(A, 20);
	for(int i=0; i<20; i++) printf("%d ", A[i]);
}
