#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void BFS(int start, vector<bool>& visited) {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void exploreComponentsBFS() {
        vector<bool> visited(V, false);
        cout << "BFS Traversal of Components:\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "Component: ";
                BFS(i, visited);
                cout << "\n";
            }
        }
    }

    void exploreComponentsDFS() {
        vector<bool> visited(V, false);
        cout << "DFS Traversal of Components:\n";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "Component: ";
                DFSUtil(i, visited);
                cout << "\n";
            }
        }
    }
};

int main() {
    Graph g(7);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    // BFS & DFS component exploration
    g.exploreComponentsBFS();
    cout << endl;
    g.exploreComponentsDFS();

    return 0;
}
