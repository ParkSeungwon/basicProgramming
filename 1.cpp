//2016110056 박승원
#include<string>
#include<random>
#include<cstring>
#include<iostream>
using namespace std;

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void merge(int* p, int* m, int* q) {
	int sz = q - p;
	int ar[sz];
	int* const partition = m;
	int* const start = p;
	for(int i=0; i<sz; i++) {
		if(p == partition) ar[i] = *m++;
		else if(m == q) ar[i] = *p++;
		else ar[i] = *p < *m ? *p++ : *m++;
	}
	memcpy(start, ar, sizeof(ar));
}

void merge_sort(int* p, int* q) {
	if(q - p <= 1) return;
	int middle = (q - p) / 2;
	merge_sort(p, p + middle);
	merge_sort(p + middle, q);
	merge(p, p + middle, q);

	for(int i=0; i<q-p; i++) cout << p[i] << ' ';
	cout << endl;
}

void iterative_merge_sort(int* p, int* q) {
	int j=2;
	for(; j<q-p; j*=2) {
		for(int* r = p; r +j/2 < q; r += j) merge(r, r + j/2, min(r + j, q));
		for(int i=0; i<10; i++) cout << p[i] << ' ';
		cout << endl;
	}
	merge(p, p + j/2, q);
}

int main(int ac, char** av) {
	int ar[] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
	iterative_merge_sort(ar, ar+10);
	cout << "비순환적 합병 정렬 결과 " << endl;
	for(int i=0; i<10; i++) cout << ar[i] << ' ';

	int ar2[] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
	merge_sort(ar2, ar2+10);
	cout << "순환적 합병 정렬 결과 " << endl;
	for(int i=0; i<10; i++) cout << ar2[i] << ' ';
}

