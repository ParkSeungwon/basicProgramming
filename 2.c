#include<stdio.h>
#include<stdlib.h>
struct Point {
	int x, y;
};

int equal(struct Point* a, struct Point* b) {
	if(a->x == b->x && a->y == b->y) return 1;
	else return 0;
}

int quadrant(struct Point* p) {
	return p->x > 0 ? (p->y > 0 ? 1 : 4) : (p->y > 0 ? 2 : 3);
}

int main() {
	struct Point a = {3, 4}, b = {3, 4}, c = {-1, -2};
	printf("%d %d\n", equal(&a, &b), equal(&b, &c));
	printf("%d %d\n", quadrant(&a), quadrant(&c));
}
