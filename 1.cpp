//2016110056 박승원

#include"tgraph.h"
using namespace std;

int main()
{
	Graph<char> gr;
	const char vert[] = "svwxmkqe";
	for(int i=0; i<8; i++) gr.insert_vertex(vert[i]);
	const char edge[][3] = {"sv", "sw", "vw", "vx", "wx", "xk", "xm", "mk", "vq", "xq", "qe", "qm"};
	for(int i=0; i<sizeof(edge)/3; i++) {
		gr.insert_edge(edge[i][0], edge[i][1], 0);
		gr.insert_edge(edge[i][1], edge[i][0], 0);
	}
	gr.view();
	cout << endl << "너비 우선 탐색 결과 : ";
	gr.breadth();
	cout << endl << "깊이 우선 탐색 결과 : ";
	gr.depth();
	cout << endl;
	
}

