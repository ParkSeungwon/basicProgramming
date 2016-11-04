#include<stdio.h>

char menus[4][20] = {"샌드위치", "햄버거", "피자", "종료"};

void print_menu() {
	for(int i=1; i<5; i++) printf("%d. %s\n", i, menus[i-1]);
	printf("원하는 메뉴를 선택하시오.");
}
void call_menu(int n) {
	printf("%s 메뉴 호출\n", menus[n]);
}

int check_menu_number(int n) {
	if(n > 0 && n < 4) return 1;
	else return 0;
}

int main()
{
	int n = -1;
	while(n != 4) {
		if(check_menu_number(n)) call_menu(n-1);
		print_menu();
		scanf("%d", &n);
	}
}

