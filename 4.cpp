//2016110056 박승원
#include<iostream>
#include<chrono>
using namespace std;


int main(int ac, char** av)
{
	auto from = chrono::system_clock::now();
	int n = atoi(av[1]);
	int ar[n+1];
	ar[n] = 0;
	for(int i=n-1; i>0; i--) {
		ar[i] = ar[i+1] + 1;
		if(i*2 <= n) ar[i] = std::min(ar[i], ar[i*2]+1);
		if(i*3 <= n) ar[i] = std::min(ar[i], ar[i*3]+1);
	}

	cout << ar[1] << endl;
	auto to = chrono::system_clock::now();
	cout << (to - from).count()/1000 << " miliseconds" << endl;
}
