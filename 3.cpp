//2016110056 박승원 
#include<iostream>
using namespace std;

int M = 40;
int c[5] = {25,20,10,5,1};
int cc[5] = {0,};//coin count
int re[5] = {0,};
int minc = 100;

int select(int m) {
	M -= c[m];
	cc[m]++;
	if(!M) {//종단 조건
		int sum = 0;
		for(int i=0; i<5; i++) sum += cc[i];//count coin
		if(sum < minc) {
			minc = sum; 
			for(int i=0; i<5; i++) re[i] = cc[i];//copy to result
		}
	}
	for(int i=0; i<5; i++) if(M >= c[i]) select(i);//브루트 포스로 선택
	M += c[m];
	cc[m]--;
}

int main()
{
	for(int i=0; i<5; i++) select(i);
	for(int i=0; i<5; i++) cout << re[i] << ' ';
}
