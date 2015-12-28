#include <iostream>
#include <list>

using namespace std;

class Graph{
	int no;
	list<int>* adj;
public:
	Graph(int n);
	void addEdge(int u, int v);
	bool is_cycle(int s, bool visited[], bool rec[]);
};

Graph::Graph(int n)
{
	no = n;
	adj = new list<int>[no];
}

void
Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool
Graph::is_cycle(int s, bool visited[], bool rec[])
{
	visited[s] = rec[s] = true;
	list<int>::iterator it;
	bool cyc = false;
	cout << s << endl;

	for (it = adj[s].begin(); it != adj[s].end(); it++) {
		if (visited[*it] && rec[*it])
			return true;
		else if (!visited[*it]) {
			cyc |= is_cycle(*it, visited, rec);
		}
	}

	rec[s] = false;
	if (cyc)
		return true;
	else
		return false;
}

int main()
{
	Graph g1(5);
	int i;

	g1.addEdge(1, 2);
	//g1.addEdge(1, 4);
	//g1.addEdge(2, 4);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	g1.addEdge(4, 1);
	
	bool *visited = new bool[5];
	bool *rec = new bool[5];
	
	for (i = 1; i <= 4; i++) {
		visited[i] = rec[i] = false;
	}

	if (g1.is_cycle(1, visited, rec))
		cout << "Graph has cycles" << endl;
	else
		cout << "No cycles" << endl;

	return 0;
}
