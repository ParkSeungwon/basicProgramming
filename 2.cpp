//2016110056 박승원 
#include<fstream>
#include<random>
using namespace std;

int main()
{
	uniform_int_distribution<> di{0,3};
	random_device rd;
	char genom[5] = "ACGT";
	ofstream f("input.txt");
	for(int i=0; i<1000000; i++) f << genom[di(rd)];
}
