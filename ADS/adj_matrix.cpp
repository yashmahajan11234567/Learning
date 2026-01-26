#include <iostream>
using namespace std;
#define V 6

void initAdjMatrix(int adjMatrix[V][V])
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[V][V], int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAdjMatrix(int adjMatrix[V][V])
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int adjMatrix[V][V];

    initAdjMatrix(adjMatrix);

    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 5);
    addEdge(adjMatrix, 4, 5);

    cout << "Adjacency Matrix:" << endl;
    printAdjMatrix(adjMatrix);

    return 0;
}
