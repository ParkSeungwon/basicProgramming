//2016110056 박승원
#include<iostream>
#include<random>
using namespace std;

int Minimum(int* p) {
	int min = 10000000;
	for(int i=0; i<1000; i++) if(p[i] < min) min = p[i];
	return min;
}

int Maximun(int* p) {
	int max = 0;
	for(int i=0; i<1000; i++) if(p[i] > max) max = p[i];
	return max;
}

pair<int, int> FindMinMax(int* p) {
	int min = 10000000, max = 0, small, large;
	for(int i=0; i<1000; i+=2) {
		if(p[i] < p[i+1]) {
			small = p[i]; 
			large = p[i+1];
		} else {
			large = p[i]; 
			small = p[i+1];
		}
		if(small < min) min = small;
		if(large > max) max = large;
	}
	return {min, max};
}


int main(int ac, char** av) {
	uniform_int_distribution<> di(1, 100000);
	random_device rd;

	int ar[1000];
	for(int i=0; i<1000; i++) ar[i] = di(rd);
	cout << Minimum(ar) << ' ' << Maximun(ar) << ' ' << endl;
	auto a = FindMinMax(ar);
	cout << a.first << ' ' << a.second << endl;
}

