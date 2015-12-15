#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Graph{
	int V; // no of vertices
	vector<int> *adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void iter_DFS(int s);
	void recurs_DFS(int s, bool visited[]);
	void iter_BFS(int s);
};

Graph::Graph(int v)
{
	V = v;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::iter_DFS(int s) {
	bool *visited = new bool[V];
	int i;
	stack<int> st;

	for (i = 0; i < V; i++)
		visited[i] = false;

	visited[s] = true;
	st.push(s);

	while(!st.empty()) {
		s = st.top();
		cout << s << " " << endl;
		st.pop();

		vector<int>::iterator it;
		for (it = adj[s].begin(); it != adj[s].end(); it++) {
			if (visited[*it] == false) {
				st.push(*it);
				visited[*it] = true;
			}
		}
	}

	delete [] visited;
}

void Graph::recurs_DFS(int s, bool visited[])
{
	if (visited[s])
		return;

	visited[s] = true;
	cout << s << endl;

	vector<int>::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++) {
		if (!visited[*it]) {
			recurs_DFS(*it, visited);
		}
	}
}

void Graph::iter_BFS(int s)
{
	bool *visited = new bool[V];
	int i = 0;

	for (i = 0; i < V; i++) {
		visited[i] = false;
	}
	visited[s] = true;

	queue<int> q;
	q.push(s);

	while(!q.empty()) {
		s = q.front();
		cout << s << endl;
		q.pop();

		for (vector<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
			if (visited[*it] == false) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
}

int main()
{
	Graph g1(5);

	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(2, 3);
	g1.addEdge(2, 4);
	g1.addEdge(4, 3);
	g1.addEdge(1, 3);

	cout << "Iterative DFS" << endl;
	g1.iter_DFS(0);

	bool *v = new bool[5];
	for(int i = 0; i < 5; i++)
		v[i] = false;	
	
	cout << endl << "Recursive DFS" << endl;
	g1.recurs_DFS(0, v);
	delete []v;

	cout << endl << "Iterative BFS" << endl;
	g1.iter_BFS(0);
	
	return 0;
}
