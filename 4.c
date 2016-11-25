#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void array_print(int *A , int size) {
	int i;
	printf("A[] = {");
	for(int i=0; i<size; i++) printf("%d,", A[i]);
	printf("\b}\n");
}

int main() {
	int A[] = {6,7,3,2,4,6,7};
	array_print(A, 7);
}


