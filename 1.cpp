//2016110056 박승원
#include<cmath>
#include <time.h>
#include<string.h>
#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

char text[] = "abababacabababcacaabbc";//A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN PATTERN STRING";
char pattern[] = "abababca";
const int t_sz = sizeof(text)-1;
const int p_sz = sizeof(pattern)-1;

void brute()
{
	for(int i=0; i<t_sz; i++) {
		bool match = true;
		for(int j=0; j<p_sz; j++) if(text[i+j] != pattern[j]) match = false;
		if(match) cout << pattern << " is found at index " << i << endl;
	}
}

unsigned long get_num_from_string(char* p, int n)
{///포인터 p로부터 n개의 문자를 하나의 숫자로 리턴한다.
	unsigned long r = 0;
	for(long i = n-1, m = 1; i >= 0; i--, m *= 26) r += (*(p+i) - 'a') * m;
	return r;
}

void rk()
{
	unsigned long pi = get_num_from_string(pattern, p_sz);
	for(int i=1; i<t_sz-p_sz+1; i++) 
		if(get_num_from_string(text+i, p_sz) == pi) 
			cout << pattern << " is found at index " << i << endl;
}

int prefixTable[p_sz];
int generate_table(char* p, int n)
{///포인터로부터 n개의 문자에서 최대 접두부의 인덱스를 반환한다..
	for(int i=n-1; i>0; i--) {//i = string length
		bool match = true;
		for(int j=0; j<i; j++) if(p[j] != p[n-i+j]) match = false;
		if(match) return i-1;
	}
	return -1;
}

void kmp()
{
	prefixTable[0] = -1;
	for(int i=0; i<p_sz; i++) prefixTable[i+1] = generate_table(pattern, i+1);
	for(char *pp = pattern, *pt = text; pt != text + t_sz;) {
		if(*pt != *pp) {
			if(pp == pattern) pt++;
			pp = pattern + prefixTable[pp - pattern] + 1;
		} else pt++, pp++;
		if(pp == pattern + p_sz) 
			cout << pattern << " is found at index " << pt - text - p_sz << endl;
	}
}
	
int main() 
{
	auto from = system_clock::now();
	brute();
	auto to = system_clock::now();
	cout << "brute " << (to - from).count()/1000 << " miliseconds" << endl;
	
	from = system_clock::now();
	rk();
	to = system_clock::now();
	cout << "rk " << (to - from).count()/1000 << " miliseconds" << endl;
	
	from = system_clock::now();
	kmp();
	to = system_clock::now();
	cout << "kmp " << (to - from).count()/1000 << " miliseconds" << endl;
}
