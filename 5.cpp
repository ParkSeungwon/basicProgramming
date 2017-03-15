//2016110056 박승원
#include<string>
#include<random>
#include<iostream>
using namespace std;

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void selection_sort(int* p, int* q) {
	if(p == q) return;
	for(int* i = p; i != q; i++) if(*p > *i) swap(p, i);
	selection_sort(p+1, q);
}

int main()
{
	int ar[] = {30, 20, 40, 10, 5, 10, 30, 15};
	selection_sort(ar, ar+8);
	for(int i=0; i<8; i++) cout << ar[i] << ' ';
}
