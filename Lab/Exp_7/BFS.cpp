#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<int> v[], int n, int start){
    vector<bool> vis(n, false);
    queue<int> q;

    vis[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto i : v[node]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}
int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<int> graph[n];
    cout << "Enter the edges in form of a pair of nodes\n";
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start; 
    cout << "Enter the node to start the BFS traversal: ";
    cin >> start;
    BFS(graph, n, start);
    return 0;
}