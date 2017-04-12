//2016110056 박승원
#include<iostream>
using namespace std;
int k=0;
bool expect(int m, int n) {
	k++;
	if(!m && !n) return false;
	if(m>0 && n>0)  return !(expect(m-1, n) && expect(m,n-1) && expect(m-1,n-1));
	else if(!m) return !expect(m, n-1);
	else if(!n) return !expect(m-1,n);
}

int main()
{
	expect(9,9);
//	for(int i=0; i<10; i++) {
//		for(int j=0; j<10; j++) cout << expect(j, i) << ' ';
//		cout << endl;
//	}
	cout << k << endl;
}
