#include<random>
#include<fstream>
#include<cstring>
#define M 1000000
#define N 100000
#define L 48
#define D 2
using namespace std;

char gene[M], person[M], short_read[N][L];

int main()
{
	uniform_int_distribution<> di{0, M-48}, percent{0, 99}, code{0, 3};
	random_device rd;
	char gene_code[4] = {'G','T','C','A'};

	//generate human gene
	ofstream f1("human_gene.txt");
	for(int i=0; i<M; i++) {
		char c = gene_code[code(rd)];
		gene[i] = c;
		f1 << c;
		if(i % 100 == 99) f1 << endl;
	}

	//write gene of a person to diagnose
	ofstream f3("person_gene.txt");
	for(int i=0; i<M; i++) {
		if(!percent(rd)) {//1% mutation rate
			char c = gene_code[code(rd)];
			f3 << c;
			person[i] = c;
		} else {
			f3 << gene[i];
			person[i] = gene[i];
		}
		if(i % 100 == 99) f3 << endl;
	}

	//generate short reads
	ofstream f4("short_read.txt");
	for(int i=0; i<N; i++) strncpy(*(short_read + i), person + di(rd), L);
	for(int i=0; i<N; i++) {
		for(int j=0; j<L; j++) f4 << short_read[i][j];
		f4 << endl;
	}
}

