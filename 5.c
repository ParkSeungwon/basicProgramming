#include<stdio.h>

int money = 0;
void save(int m) {
	money += m;
}
void draw(int m) {
	money -= m;
}

int main() {
	int menu, m, end = 0;
	while(!end) {
		printf("메뉴를 선택하세요: 저축(1), 인출(2)");
		scanf("%d", &menu);
		if(menu == 1) {
			printf("저축할 금액:");
			scanf("%d", &m);
			save(m);
		} else if(menu == 2) {
			printf("인출할 금액:");
			scanf("%d", &m);
			draw(m);
		} else end = 1;
		printf("현재 잔액은 %d입니다.\n", money);
	}
}



