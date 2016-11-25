#include<stdio.h>

int search(int *A, int size, int search_value) {
	int i;
	for(i=0; i<size; i++) {
		if(A[i] == search_value) return i;
	}
}

int main() {
	int A[10] = {234, 231, 255, 300, 400, 424, 232, 332, 200, 190};
	printf("월급이 200만원인 사람은 %d번째입니다.\n", 1+search(A, 10, 200));
}
