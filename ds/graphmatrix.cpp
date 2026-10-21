#include <iostream>
using namespace std;

#define MAX_VERTICES 10

class GraphMatrix {
private:
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        // Initialize matrix with 0s
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // For undirected graph
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    GraphMatrix g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    return 0;
}
