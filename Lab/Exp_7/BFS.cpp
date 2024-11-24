#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(int start, vector<int> graph[], vector<bool>& visited) {
    queue<int> q; 
    visited[start] = true; 
    q.push(start); 
    cout << "BFS Traversal starting from node " << start + 1 << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node + 1 << " ";
        for (int i : graph[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
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
    cout << "Enter the node to start the BFS traversal: ";
    int start; cin >> start; start--;
    vector<bool> visited(n, false);
    BFS(start, graph, visited);
    return 0;
}