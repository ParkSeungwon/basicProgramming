#pragma once
#include<algorithm>
#include"tgraph.h"

template <typename T> class Tree : public Graph<T>
{
public:
	void insert(T n) {
		Vertex<T>* p = new Vertex<T>;
		p->data = n;
		p->edge = Graph<T>::insert(p->edge, nullptr, 0);
		p->edge = Graph<T>::insert(p->edge, nullptr, 0);
		Graph<T>::root = insert(Graph<T>::root, p);
	}
	
	Vertex<T>* find(T n) {
		return find(Graph<T>::root, n);
	}
	
	int height() {
		return height(Graph<T>::root);
	}
	
	Vertex<T>* data() {
		connect();
		return Graph<T>::root;
	}

	void view() {
		connect();
		Graph<T>::view();
	}
		
protected:
	std::vector<Vertex<T>*> vts;
	
	void connect() {
		vts.clear();
		connect(Graph<T>::root);
		Vertex<T>* p = Graph<T>::root;
		for(int i=1; i<vts.size(); i++) {
			p->vertex = vts[i];
			p = p->vertex;
		}
	}

private:
	void connect(Vertex<T>* p) {//connect vertexes for graph compatibility
		if(!p) return;
		vts.push_back(p);
		if(p->edge) {
			connect(p->edge->vertex);
			connect(p->edge->edge->vertex);
		}
	}

	int height(Vertex<T>* tree) {
		if(!tree) return 0;
		if(!tree->edge) return 1;
		return 1 + std::max(height(tree->edge->vertex), height(tree->edge->edge->vertex));
	}

	Vertex<T>* find(Vertex<T>* p, T n) {
		if(!p) return nullptr;
		if(p->data == n) return p;//all below is <else if> due to return
		if(n < p->data) {
			p->edge->v = 1;
			return find(p->edge->vertex, n);
		} else {
			p->edge->edge->v = 1;
			return find(p->edge->edge->vertex, n);
		}
	}

	Vertex<T>* insert(Vertex<T>* p, Vertex<T>* n) {//insert by comparing value
		if(!p) return n;						//to make binary tree
		if(n->data < p->data) p->edge->vertex = insert(p->edge->vertex, n);
		else p->edge->edge->vertex = insert(p->edge->edge->vertex, n);

		//avl tree rotate
		int ll=0, rr=0, lr=0, rl=0, r=0, l=0;
		if(p->edge->vertex) {
			ll = height(p->edge->vertex->edge->vertex);
			lr = height(p->edge->vertex->edge->edge->vertex);
			l = 1 + std::max(ll, lr);
		}
		if(p->edge->edge->vertex) {
			rr = height(p->edge->edge->vertex->edge->edge->vertex);
			rl = height(p->edge->edge->vertex->edge->vertex);
			r = 1 + std::max(rl, rr);
		}
		if(abs(l-r) > 1) {
			int ar[] = {ll, lr, rr, rl};
			int biggest = *std::max_element(ar, ar+4);
			if(biggest == ll) return rotate_LL(p);
			else if(biggest == rr) return rotate_RR(p);
			else if(biggest == lr) {
				p->edge->vertex = rotate_RR(p->edge->vertex);
				return rotate_LL(p);
			} else if(biggest == rl) {
				p->edge->edge->vertex = rotate_LL(p->edge->edge->vertex);
				return rotate_RR(p);
			}
		}
		return p;
	}

	Vertex<T>* rotate_LL(Vertex<T>* A) {
		Vertex<T>* B = A->edge->vertex;
		A->edge->vertex = B->edge->edge->vertex;
		B->edge->edge->vertex = A;
		return B;
	}
	
	Vertex<T>* rotate_RR(Vertex<T>* A) {
		Vertex<T>* B = A->edge->edge->vertex;
		A->edge->edge->vertex = B->edge->vertex;
		B->edge->vertex = A;
		return B;
	}	
};
