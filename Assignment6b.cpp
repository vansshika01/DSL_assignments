#include<bits/stdc++.h>
using namespace std;

void dfs_non_recursive(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        cout << node << " "; // Print the node as part of the connected component

        // Visit all neighbors of the current node
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int V; cin>>V;
    int edges; cin>>edges;
    vector<vector<int>> adj(V);
    
    for(int i=0;i<edges;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    vector<bool> visited(V, false); // Keep track of visited nodes

    // Traverse all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            cout << "Component: ";
            dfs_non_recursive(adj, i, visited); 
            cout << endl;
        }
    }

    return 0;
}
