//2016110056 박승원 
#include<iostream>
using namespace std;

int main()
{
	int M = 40;
	int c[5] = {25,20,10,5,1};
	int co[5]{0,};
	while(M > 0) for(int i=0; i<5; i++) while(M >= c[i]) {
		M -= c[i];
		co[i]++;
	}
	for(int i=0; i<5; i++) cout << co[i] << ' ';
}
