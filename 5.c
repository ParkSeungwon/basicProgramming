#include<stdio.h>
#include<string.h>

enum Type {triangle, rectangle, circle};
union Shape {
	int radius;
	int value[2];
};
char yn[2];

int main() {
	enum Type t;
	union Shape s;
	do {
		printf("종류선택(0.삼각형, 1.사각형, 2.원):");
		scanf("%d", &t);
		switch(t) {
			case circle:
				printf("원의 반지름을 입력하세요");
				scanf("%d", &s.radius);
				break;
			case triangle:
				printf("삼각형의 밑변과 높이를 입력하세요");
				scanf("%d %d", &s.value[0], &s.value[1]);
				break;
			case rectangle:
				printf("사각형의 가로와 세로를 입력하세요");
				scanf("%d %d", &s.value[0], &s.value[1]);
				break;
		}
		printf("y 계속/n 멈춤 선택하세요 : ");
		scanf("%s", yn); 
	} while(!strcmp(yn, "y"));
}



