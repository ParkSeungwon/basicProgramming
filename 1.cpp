//2016110056 박승원
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

typedef struct Tree {
	int num;
	struct Tree *left, *right;
} Tree;

Tree* insert(Tree* p, int num) {//삽입 재귀 함수
	if(!p) {
		p = (Tree*)malloc(sizeof(Tree));
		p->num = num;
		p->left = NULL;
		p->right = NULL;
	} else if(num > p->num) p->right = insert(p->right, num);
	else p->left = insert(p->left, num);
	return p;//리턴값은 (재귀적 호출시)항상 부모와 연결할 값이라고 생각하면 된다.
}

void show(Tree* p) {//중위 순회 출력 함수
	if(p->left) show(p->left);
	printf("%d\n", p->num);
	if(p->right) show(p->right);
}

Tree* del_node(Tree* p) {//p가 가르키는 노드를 삭제한다.
	if(!p->left && !p->right) {//자식이 없을 때
		free(p);
		return NULL;
	} else if(!p->right) {//오른쪽만 널일때
		Tree *r = p->left;
		free(p);
		return r;//리턴값을 대입하는 형식으로 부모와 연결한다.
	} else if(!p->left) {//왼쪽만 널일때
		Tree *r = p->right;
		free(p);
		return r;
	} else {//둘 다 자식일때
		Tree* prev = p;
		Tree* q = p->right;
		for(; q->left; q = q->left) prev = q;
		p->num = q->num;
		if(prev == p) prev->right = del_node(q);//q를 재귀적으로 삭제하고 이어준다.
		else prev->left = del_node(q);
		return p;
	}
}

Tree* del(Tree* p, int num) {//num 요소를 삭제한다. 
	if(!p) return NULL;
	if(p->num == num) return del_node(p);//del_node를 호출한다.
	if(p->num > num) p->left = del(p->left, num);
	if(p->num < num) p->right = del(p->right, num);
	return p;
}

Tree* find(Tree* p, int num) {//조회
	if(!p) return NULL;
	if(p->num == num) return p;
	if(p->num > num) return find(p->left, num);
	if(p->num < num) return find(p->right, num);
}

void free_tree(Tree* p) {
	if(p->left) free_tree(p->left);
	if(p->right) free_tree(p->right);
	free(p);
}

int main()
{
	Tree* tree = NULL;
	tree = insert(tree, 20);//최초 삽입 이외에는
	insert(tree, 6);//tree에서는 삽입시 루트가 바뀌지 않으므로 
	insert(tree, 2);//대입하지 않아도 된다.
	insert(tree, 4);
	insert(tree, 16);
	insert(tree, 10);
	insert(tree, 8);
	insert(tree, 12);
	insert(tree, 14);
	insert(tree, 9);
	show(tree);
	printf("===============\n");
	Tree* p = find(tree, 10);//조회 
	cout << p->left->num << " , " << p->right->num << endl;
	del(tree, 6);
	p = find(tree, 10);//조회 
	cout << p->left->num << " , " << p->right->num << endl;
	free_tree(tree);
}
