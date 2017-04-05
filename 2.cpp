//2016110056 박승원 
#include<iostream>
using namespace std;

int fibo(int n) {//print 1 to n fibo array
	int a[3];
	a[0] = 1; a[1] = 1; a[2] = 0;
	for(int i=1; i<=n; i++) {
		a[i%3] = a[(i-1)%3] + a[(i+1)%3];
		cout << a[i%3] << ' ';
	}
}

int main()
{
	fibo(20);
}
