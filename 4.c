#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


int main()
{
	int x1, y1, x2, y2;
	printf("첫번째 점의 좌표를 입력하세요.(x, y)");
	scanf("%d %d", &x1, &y1);
	printf("두번째 점의 좌표를 입력하세요.(x, y)");
	scanf("%d %d", &x2, &y2);
	printf("두 점 사이의 거리는 %lf입니다.\n", distance(x1, y1, x2, y2));
}
