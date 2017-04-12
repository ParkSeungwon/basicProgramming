//2016110056 박승원 
#include<array>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<array<int, 3>> v;
void Cameleon(int a, int b, int c)
{
	int k=0;
	if(!a) k++; if(!b) k++; if(!c) k++;
	if(k == 2) {
		cout << "changed to one color" << endl;
		return;
	}
	if(a<0 || b<0 || c<0) return;
	array<int, 3> ar;
	ar[0] = a; ar[1] = b; ar[2] = c;
	if(find(v.begin(), v.end(), ar) != v.end()) return;
	else v.push_back(ar);
	Cameleon(a-1, b-1, c+2);
	Cameleon(a+2, b-1, c-1);
	Cameleon(a-1, b+2, c-1);
}


int main()
{
	cout << "first case" << endl;
	Cameleon(1,3,5);
	cout << "second case" << endl;
	Cameleon(37,61,27);
}

