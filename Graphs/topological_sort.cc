#include <iostream>
#include <list>

using namespace std;

class Graph {
	int no;
	list<int> *adj;
public:
	Graph(int n);
	void addEdge(int u, int v);
	void DFS(int s, bool visited[]);
	void topo();
};

Graph::Graph(int n)
{
	no = n;
	adj = new list<int>[n];
}

void
Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void
Graph::DFS(int s, bool visited[])
{
	if (visited[s] == true)
		return;

	visited[s] = true;
	list<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++) {
		if (!visited[*it])
			DFS(*it, visited);
	}

	cout << s << endl;
}

void
Graph::topo()
{
	bool *visited = new bool[no];
	int i;

	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(1, 2);
	addEdge(1, 6);
	addEdge(2, 4);
	addEdge(2, 5);
	addEdge(4, 6);
	addEdge(5, 6);
	

	for (i = 0; i < no; i++) {
		visited[i] = false;
	}

	for (i = 0; i < no; i++) {
		if (visited[i] == false)
			DFS(i, visited);
	}

}

int main()
{
	Graph g1(8);
	g1.topo();
	return 0;
}
