//2016110056 박승원
#include<iostream>
using namespace std;

void germs(int& bacteria, int& virus) {
	bacteria -= virus;
	bacteria *= 2;
	virus *=2;
}

int main()
{
	int bacteria=100000, virus=1, minute;
	for(minute=0; bacteria>0; minute++) germs(bacteria, virus);
	cout << minute << endl;
}
