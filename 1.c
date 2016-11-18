#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int num[10] = {0,};
	srand(time(NULL));
	for(int i=0; i<100; i++) num[rand()%10]++;
	int max = -1, index;
	for(int i=0; i<10; i++) if(max < num[i]) {
		index = i; 
		max = num[i];
	}
	printf("%d가 %d번으로 가장 많이 생성되었습니다.\n", index, num[index]);
}
