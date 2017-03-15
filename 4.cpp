//2016110056 박승원
#include<iostream>
using namespace std;

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int main()
{
	int ar[] = {30, 20, 40, 10, 5, 10, 30, 15};
	for(int i=0; i<8; i++) for(int j=i+1; j<8; j++) {
		if(ar[i] > ar[j]) swap(ar +i, ar + j);
		for(int i=0; i<8; i++) cout << ar[i] << ' ';
		cout << endl;
	}
	for(int i=0; i<8; i++) cout << ar[i] << ' ';
}

