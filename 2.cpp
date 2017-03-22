//2016110056 박승원 
#include<iostream>
#include<stdio.h>
#define MAX 300
using namespace std;
typedef int element;
element heap[MAX];
int sz = 0;

void swap(element* a, element* b) {
	element tmp = *a;
	*a = *b;
	*b = tmp;
}

int threesome(int i) {
	if(heap[i] < heap[i * 2] || heap[i] < heap[i * 2 + 1]) {
		int big = heap[i*2] > heap[i*2+1] ? i*2 : i*2+1;
		swap(&heap[big], &heap[i]);
		return big;
	} else return 0;
}

void insert(element n) {
	heap[++sz] = n;
	for(int i=sz; i>1; i/=2) 
		if(heap[i] > heap[i/2]) swap(&heap[i], &heap[i/2]);
		else break;
}

void show() {
	for(int i=1; i<=sz; i++) printf("%d ", heap[i]);
}

element pop() {
	heap[0] = heap[1];//use for return 
	heap[1] = heap[sz--];
	int n = 1;
	while(n) n = threesome(n);
	return heap[0];
}


int main()
{
	int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	for(auto& a : A) insert(a);
	for(int i=0; i<sz; i++) cout << heap[i] << ' ';
	cout << endl;
	int B[10];
	for(int i=0; sz; i++) B[i] = pop();
	for(int i=0; i<10; i++) cout << B[i] << ' ';
}
