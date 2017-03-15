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

void quick_sort(int* p, int* q) {
	if(p+1 >= q) return;
	int* partition = p++;
	int* end = q--;
	while(p < q) {
		while(*p <= *partition && p != end) p++;
		while(*q >= *partition && q != partition) q--;
		if(p < q) swap(p, q);
	}
	if(*partition > *q) swap(partition, q);//in case only 2 elements p,q will point to the same the 2nd element without comparing the values.
	quick_sort(partition, q);
	quick_sort(q+1, end); 
}

bool is_palindrome(char* f, char* r) {
	if(f >= r) return true;
	if(*f == *r) return is_palindrome(f+1, r-1);
	else return false;
}

bool is_palindrome(char* p) {
	char *f = p;
	char *r = p;
	while(*++r);
	r -= 1;
	return is_palindrome(f, r);
}

bool check_ar(int* p, int* q) {
	while(p + 1 != q) if(*p > *++p) return false;
	return true;
}

int main(int ac, char** av) {
	int ar[10000];
	uniform_int_distribution<> di(1,20000);
	random_device rd;
	for(int j=0; j<1; j++) {
		for(int i=0; i<10000; i++) ar[i] = di(rd);
		quick_sort(ar, ar+10000);
		for(int i=0; i<10000; i++) cout << ar[i] << ' ';
		cout << endl;
		cout << (check_ar(ar, ar+10000) ? "well" : "not") << " alligned" << endl;
	}
}

