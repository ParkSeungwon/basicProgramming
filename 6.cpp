//2016110056 박승원 
#include<iostream>
using namespace std;

int rr[2][100][6];//to compare two result
const int c[6] = {25,20,15,10,5,1};
int co[6]{0,};//coint count
int re[6] = {0,};//result for recursive function
int M;
int minc = 100;//

void select(int m) {
	M -= c[m];
	co[m]++;
	int sum = 0;
	for(int i=0; i<6; i++) sum += co[i];//count coin
	if(sum > minc) return;
	if(!M) {//종단 조건
		int sum = 0;
		for(int i=0; i<6; i++) sum += co[i];//count coin
		if(sum < minc) {
			minc = sum; 
			for(int i=0; i<6; i++) re[i] = co[i];//copy to result
		}
	}
	for(int i=0; i<6; i++) if(M >= c[i]) select(i);//브루트 포스로 선택
	M += c[m];
	co[m]--;
}

int main()
{
	for(int k = 1; k<=100; k++) {
		M = k;
		while(M > 0) for(int i=0; i<6; i++) while(M >= c[i]) {
			M -= c[i];
			co[i]++;
		}
		for(int i=0; i<6; i++) rr[0][k-1][i] = co[i];
		for(int i=0; i<6; i++) co[i] = 0;
	}

	for(int k=1; k<=100; k++) {
		M = k;
		for(int i=0; i<6; i++) select(i);
		for(int i=0; i<6; i++) {
			rr[1][k-1][i] = re[i];
			co[i] = 0;
		}
		minc = 100;
	}

	for(int i=0; i<100; i++) for(int j=0; j<6; j++) 
		if(rr[0][i][j] != rr[1][i][j]) cout << i << endl;
}
