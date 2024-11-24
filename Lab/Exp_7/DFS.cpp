#include <iostream>
#include <vector>
using namespace std;
void DFS(int node, vector<int> graph[], vector<bool>& visited) {
    visited[node] = true;
    cout << node + 1 << " ";
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) DFS(neighbor, graph, visited); 
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<int> graph[n];
    cout << "Enter the edges in form of a pair of nodes (u, v):\n";
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "Enter the node to start the DFS traversal: ";
    int start; cin >> start; start--; 
    vector<bool> visited(n, false);
    cout << "DFS Traversal starting from node " << start + 1 << ": ";
    DFS(start, graph, visited);
    cout << endl;

    return 0;
}