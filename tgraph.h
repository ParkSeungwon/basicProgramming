#pragma once
#include<climits>
#include<cassert>
#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<stack>
#define min(a, b) a < b ? a : b

template <typename T> class Vertex;

template<typename T> class Edge
{
public:
	int weight = 0;
	int v = 0;//for visit check or other uses like dijkstra route check
	struct Vertex<T>* vertex = nullptr;
	struct Edge<T>* edge = nullptr;
};

template<typename T> class Vertex
{
public:
	T data;
	int v = 0;//for visit check or other uses like parity bit
	struct Edge<T>* edge = nullptr;
	struct Vertex<T>* vertex = nullptr;
};

///This class does not make its own data structure it just deals with pointers 
///and allocate memory for data. Thus enhance interoperability with C style data
///structure. It arange data like below. V->vertex always points to the next line, 
///E->edge always points to the next one, while E->vertex point to the other
///edge irregularly with direction.
/// V - E - E - E - E
/// V - E - E
/// V - E - E - E
template<typename T> class Graph
{
public:
	virtual ~Graph() {
		gfree(root);
		root = nullptr;
	}

	void insert_vertex(T n) {
		root = insert(root, n);
	}
	
	void insert_edge(T a, T b, int weight) {
		Vertex<T> *va, *vb;
		for(Vertex<T>* p = root; p; p = p->vertex) {
			if(p->data == a) va = p;
			if(p->data == b) vb = p;
		}
		va->edge = insert(va->edge, vb, weight);
	}
	
	void read_file(std::string file) {
		T n1, n2;
		std::ifstream f(file);
		int vc;
		f >> vc;
		for(int i=0; i<vc; i++) {
			f >> n1;
			insert_vertex(n1);
		}
		int wt;
		while(f >> n1 >> n2 >> wt) insert_edge(n1, n2, wt);
	}

	void view() {
		for(Vertex<T>* p = root; p; p = p->vertex) {
			std::cout << p->data << " : ";
			for(Edge<T>* e = p->edge; e; e = e->edge) 
				if(e->vertex) std::cout << '<' << p->data << ',' << e->vertex->data << '>' << e->weight << ' '; 
			std::cout << std::endl;
		}
	}
	
	Vertex<T>* data() {//this is to make compatible with C structure, 
		return root;//return root pointer, GraphV will access it.
	}
	
	void prim() {
		clearv();
		root->v = 1;//below for syntax is just to call n-1 times
		for(Vertex<T>* q = root->vertex; q; q = q->vertex) shortest(root);
	}
	
	void topology() {//check v to entry and print data
		clearv();
		for(Vertex<T>* q; q = find_entry(root);) {
			q->v = 1;
			std::cout << q->data << " - ";
		}
	}

	int floyd(T a, T b) {
		clearv();
		std::map<T, std::map<T, int>> A;
		for(Vertex<T>* q = root; q; q = q->vertex) 
			for(Vertex<T>* p = root; p; p = p->vertex) 
				A[q->data][p->data] = INT_MAX / 2;
		for(Vertex<T>* q = root; q; q = q->vertex) 
			for(Edge<T>* e = q->edge; e; e = e->edge) 
				A[q->data][e->vertex->data] = e->weight;
		
		for(Vertex<T>* k = root; k; k = k->vertex) 
			for(Vertex<T>* i = root; i; i = i->vertex) 
				for(Vertex<T>* j = root; j; j = j->vertex) 
					A[i->data][j->data] = min(A[i->data][j->data], 
							A[i->data][k->data] + A[k->data][j->data]);
		return A[a][b];
	}
	
	int dijkstra(T a, T b) {
		clearv();
		distance.clear();
		for(Vertex<T>* p = root; p; p = p->vertex) distance[p] = INT_MAX / 2;
		Vertex<T>* pa = find(root, a); assert(pa);
		Vertex<T>* pb = find(root, b); assert(pb);
		distance[pa] = 0;
		while(pb != find_closest());
		for(auto& a : waypoint[pb]) a->v = 1;
		return distance[pb];
	}
	
	void depth() {
		clearv();
		depth(root);
	}
	
	void breadth() {
		clearv();
		std::cout << root->data << ' ';
		root->v = 1;
		breadth(root);
	}

	void euler() {//for directed graph
		clearv();
		Vertex<T>* p;
		int edge_count = 0;
		for(p = root; p; p = p->vertex) {
			for(Edge<T>* e = p->edge; e; e = e->edge) {
				p->v++;//out grade
				e->vertex->v--;//in grade
				edge_count++;
			}
		}
		for(p = root; p; p = p->vertex) if(p->v == 1) break;//starting point
		euler_visit(p, 0, edge_count);
	}

	void euler_visit(Vertex<T>* p, int n, int edge_count) {
		if(n == edge_count) view();//if all the edges are visited
		for(Edge<T>* e = p->edge; e; e = e->edge) {
			if(!e->v) {//if not visited
				e->v = 1;//mark visited
				e->weight = n+1;//use weight to show visit order
				euler_visit(e->vertex, n+1, edge_count);
				e->v = 0;//remove visited mark
			}
		}
	}

	
	void bridge() {
		clearv();
		std::vector<Edge<T>*> v;
		for(Vertex<T>* p = root; p; p = p->vertex) 
			for(Edge<T>* e = p->edge; e; e = e->edge)
				if(is_bridge(p, e)) v.push_back(e);
		for(auto& a : v) a->v = 1;
	}
	
	void greedy() {
		clearv();
		union_set.clear();
		int i = 1;
		for(Vertex<T>* p = root; p; p = p->vertex) union_set[p] = i++;
		std::vector<Edge<T>*> v;
		for(Vertex<T>* p = root->vertex; p; p = p->vertex) v.push_back(find_greed());
		clearv();
		for(auto& a : v) a->v = 1;
	}

protected:
	Vertex<T>* root = nullptr;
	
	Vertex<T>* insert(Vertex<T>* p, T n) {//recursively insert a value 'n'
		if(!p) {
			p = new Vertex<T>;
			p->data = n;
			return p;
		}
		p->vertex = insert(p->vertex, n);
		return p;
	}
	
	Edge<T>* insert(Edge<T>* e, Vertex<T>* v, int weight) {
		if(!e) {//recursively insert edge in at the end of e pointint to v
			e = new Edge<T>;
			e->vertex = v;
			e->weight = weight;
			return e;
		}
		e->edge = insert(e->edge, v, weight);
		return e;
	}
	
	bool is_bridge(Vertex<T>* p, Edge<T>* eg) {//check all the bridges in the graph
		eg->v = 1;
		for(Edge<T>* e = eg->vertex->edge; e; e = e->edge) 
			if(e->vertex == p) e->v = 1;
		depth(eg->vertex);
		bool r = !p->v;
		clearv();
		return r;
	}

private:
	std::map<Vertex<T>*, int> distance;
	std::map<Vertex<T>*, std::vector<Edge<T>*>> waypoint;
	std::map<Vertex<T>*, int> union_set;
	
	Vertex<T>* find_closest() {//dijkstra
		int min = INT_MAX / 2;
		Vertex<T>* p = nullptr;
		for(auto& a : distance) if(min > a.second && !a.first->v) {
			p = a.first;
			min = a.second;
		}
		p->v = 1;
		for(Edge<T>* e = p->edge; e; e = e->edge) if(!e->vertex->v) {
			if(distance[e->vertex] > distance[p] + e->weight) {
				distance[e->vertex] = distance[p] + e->weight;
				waypoint[e->vertex] = waypoint[p];
				waypoint[e->vertex].push_back(e);
			}
		}
		//for(auto& a : distance) std::cout << a.first->data << ' ' << a.second << 
		//	' ' << a.first->v << std::endl;
		return p;
	}
	
	Vertex<T>* find(Vertex<T>* p, T n) {//find value 'n' and return the address
		for(Vertex<T>* v = p; v; v = v->vertex) if(v->data == n) return v;
	}
	
	void depth(Vertex<T>* p) {//depth search the graph
		assert(p);
		p->v = 1;
		std::cout << p->data << ' ';
		for(Edge<T>* e = p->edge; e; e = e->edge) {
			if(!e->vertex->v && !e->v) {//!e->v is for bridge func
				e->v = 1;
				depth(e->vertex);
			}
		}
	}
	
	void breadth(Vertex<T>* p) {
		std::vector<Vertex<T>*> q;
		for(Edge<T>* e = p->edge; e; e = e->edge) {
			if(!e->vertex->v) {
				q.push_back(e->vertex);
				e->v = 1;
				std::cout << e->vertex->data << ' ';
				e->vertex->v = 1;
			}
		}
		for(auto& a : q) breadth(a);
	}
	
	void efree(Edge<T>* e) {
		if(!e) return;
		efree(e->edge);
		delete e;
	}
	
	void gfree(Vertex<T>* p) {
		if(!p) return;
		efree(p->edge);
		gfree(p->vertex);
		delete p;
	}
	
	void clearv() {
		for(Vertex<T>* p = root; p; p = p->vertex) {
			p->v = 0;
			for(Edge<T>* e = p->edge; e; e = e->edge) e->v = 0;
		}
	}
	
	void shortest(Vertex<T>* p) {//prim
		Edge<T>* me;
		int min = INT_MAX;
		for(; p; p = p->vertex) {
			if(p->v) {
				for(Edge<T>* e = p->edge; e; e = e->edge) {
					if(e->v) continue;
					if(e->weight < min && !e->vertex->v) {
						min = e->weight;
						me = e;
					}
				}
			}
		}
		me->v = 1;
		me->vertex->v = 1;
	}
	
	Vertex<T>* find_entry(Vertex<T>* p) {//return NULL when no more,topology
		for(Vertex<T>* q = p; q; q = q->vertex) {
			if(q->v != 1) {//1 or 2 or 0
				for(Edge<T>* e = q->edge; e; e = e->edge) {
					if(!e->vertex->v) e->vertex->v = 2;//entry marking
				}
			}
		}
		Vertex<T>* r = NULL;
		for(Vertex<T>* q = p; q; q = q->vertex) {
			if(q->v == 2) q->v = 0;
			else if(!q->v) r = q;
		}
		return r;
	}
	
	void unite(Vertex<T>* a, Vertex<T>* b) {//greed
		for(auto& u : union_set) 
			if(u.second == union_set[a]) u.second = union_set[b];
	}
	
	Edge<T>* find_greed() {
		int min = INT_MAX / 2;
		Edge<T>* eg;
		Vertex<T>* vt;
		for(Vertex<T>* p = root; p; p = p->vertex) {
			for(Edge<T>* e = p->edge; e; e = e->edge) {
				if(!e->v && e->weight < min) {
					min = e->weight;
					eg = e;
					vt = p;
				}
			}
		}
		eg->v = 1;
		if(union_set[vt] != union_set[eg->vertex]) {
			unite(vt, eg->vertex);
			return eg;
		} else return find_greed();
	}
};



