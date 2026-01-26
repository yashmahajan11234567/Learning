#include<iostream>
#include<vector>
using namespace std;

class graph {
	
	public:
		int n;
		
		vector < vector <int> > adj_matrix;
		graph(int vertices)
		{
		n = vertices;
			adj_matrix.resize(n, vector<int> (n,0));
		}
		
		void add_edge(int u, int v)
		{
			adj_matrix[u][v] = 1;
			adj_matrix[v][u] = 1;
		}
		
		void print()
		{ 
			cout << "Adjacency Matrix for the group: "<< endl;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					cout << adj_matrix[i][j] << " ";
				}
				cout << endl; 
			}
		}
};

int main()
{
	int n = 4;
	graph g(n);
	
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.add_edge(2,3);

	g.print();
	
	return 0;
}
