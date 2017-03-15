//2016110056 박승원 
#include<iostream>
using namespace std;

struct Coin 
{
	int M = 40;
	int c[100] = {25,20,10,5,1,0,};
	int cc[100] = {0,};//coin count
	int re[100] = {0,};//result
	int minc = 100;//minimum coin
	int d = 5;

	int select(int m) {
		M -= c[m];
		cc[m]++;
		if(!M) {//종단 조건
			int sum = 0;
			for(int i=0; i<d; i++) sum += cc[i];//count coin
			if(sum < minc) {
				minc = sum; 
				for(int i=0; i<d; i++) re[i] = cc[i];//copy to result
			}
		}
		for(int i=0; i<d; i++) if(M >= c[i]) select(i);//브루트 포스로 선택
		M += c[m];
		cc[m]--;
	}

	int result()
	{
		int sum = 0;
		for(int i=0; i<d; i++) select(i);
		for(int i=0; i<d; i++) sum += re[i];
		cout << "필요한 동전 갯수 " << sum << " : ";
		for(int i=0; i<d; i++) cout << re[i] << ' ';
		cout << endl;
	}
};

int main()
{
	Coin A, B;

	A.c[2] = 15; A.c[3] = 10; A.c[4] = 5; A.c[5] = 1;
	A.d = 6;
	A.result();

	B.M=11;
	B.c[0]=1; B.c[1]=3; B.c[2]=5;
	B.d = 3;
	B.result();
}

