#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dice[7];

int d_rand() { 
	static int count = 0;
	count++;
	dice[rand() % 6 + 1]++;
	return count;
}

int main()
{
	srand(time(NULL));

	while(1) {
		int k = d_rand();
		if(k%100 == 0) {
			for(int i=1; i<7; i++) printf("%d ", dice[i]);
			printf("\n");
		}
		if(k == 5000) break;
	}
}
