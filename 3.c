#include<stdio.h>
#include<stdlib.h>

int b_rand() { 
	srand(time(NULL));
	return rand() % 2; 
}

int main()
{
	int side;
	char yesno[2];
here:
	printf("앞면 또는 뒷면 <1 또는 0>?");
	scanf("%d", &side);
	if(b_rand() == side) printf("맞았습니다.\n");
	else printf("틀렸습니다.\n");
	printf("계속하시겠습니까?(y또는 n)");
	scanf("%s", &yesno);
	if(yesno[0] == 'y') goto here;
}
