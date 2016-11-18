#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand(time(NULL));
	int exam[10][3];
	for(int y=0; y<10; y++) for(int x=0; x<3; x++) exam[y][x] = rand() % 100;
	printf("학번 :	 시험1	시험2	시험3	최대 	최소\n");
	for(int y=0; y<10; y++) {
		int max=0, min=100;
		for(int x=0; x<3; x++) {
			exam[y][x] > max ? max = exam[y][x] : 0;
			exam[y][x] < min ? min = exam[y][x] : 0;
			if(x == 2) printf("%d :	 %d	%d	%d	%d	 %d\n", y+1, exam[y][0], exam[y][1], exam[y][2], max, min);
	}
	}
}


