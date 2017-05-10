//2016110056 박승원 
#include<string>
#include<set>
#include"tgraph.h"
using namespace std;

int main()
{
	const string vert[] = {"AGT", "AAA", "ACT", "AAC", "CTT", "GTA", "TTT", "TAA"};

	Graph<string> gr;
	for(int i=0; i<8; i++) gr.insert_vertex(vert[i]);
	for(int i=0; i<8; i++) for(int j=0; j<8; j++) 
		if(i != j && vert[i][1] == vert[j][0] && vert[i][2] == vert[j][1])
			gr.insert_edge(vert[i], vert[j], 0);
	cout << "Hamiltonian" << endl;
	gr.view();
	gr.depth();

	Graph<string> euler;
	set<string> imer;
	for(auto s : vert) {
		imer.insert(s.substr(1));
		s.pop_back();
		imer.insert(s);
	}
	for(auto a : imer) euler.insert_vertex(a);
	euler.insert_edge("AA", "AC", 0);
	euler.insert_edge("AC", "CT", 0);
	euler.insert_edge("CT", "TT", 0);
	euler.insert_edge("TT", "TA", 0);
	euler.insert_edge("AG", "GT", 0);
	euler.insert_edge("AA", "AG", 0);
	euler.insert_edge("GT", "TT", 0);
	euler.insert_edge("TA", "AA", 0);
	cout << endl << "Eulerian" << endl;
	euler.view();
	euler.depth();
	cout << endl;
	euler.euler();
}

