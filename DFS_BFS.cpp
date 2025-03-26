#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


void DFS(int start, int vertices, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
}


void BFS(int start, int vertices, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


void DFSUtil(int node, int vertices, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) {
            DFSUtil(i, vertices, adjMatrix, visited);
        }
    }
}


bool isConnected(int vertices, vector<vector<int>>& adjMatrix) {
    vector<bool> visited(vertices, false);


    DFSUtil(0, vertices, adjMatrix, visited);


    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}


int countConnectedComponents(int vertices, vector<vector<int>>& adjMatrix) {
    vector<bool> visited(vertices, false);
    int count = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFSUtil(i, vertices, adjMatrix, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  
    }


    int start;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> start;

    vector<bool> visitedDFS(n, false);
    cout << "DFS Traversal starting from node " << start << ": ";
    DFS(start, n, adjMatrix, visitedDFS);
    cout << endl;

    vector<bool> visitedBFS(n, false);
    cout << "BFS Traversal starting from node " << start << ": ";
    BFS(start, n, adjMatrix, visitedBFS);
    cout << endl;


    if (isConnected(n, adjMatrix)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is NOT connected." << endl;
        cout << "The number of connected components is: " << countConnectedComponents(n, adjMatrix) << endl;
    }

    return 0;
}
