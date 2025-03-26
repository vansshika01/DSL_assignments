#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent, parent[i]); 
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}


void kruskal(int vertices, vector<vector<int>>& adjMatrix) {

    vector<Edge> edges;

 
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {  
            if (adjMatrix[i][j] != 0) {
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }


    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int parent[vertices], rank[vertices];
    
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<Edge> mst;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        int rootU = find(parent, u);
        int rootV = find(parent, v);


        if (rootU != rootV) {
            mst.push_back(edge);
            unionSets(parent, rank, rootU, rootV);
        }
    }


    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    int mstWeight = 0;
    for (auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        mstWeight += edge.weight;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int vertices, edgesCount;


    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;

 
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        int u, v, weight;
        cout << "Edge " << i + 1 << " (u v weight): ";
        cin >> u >> v >> weight;

    
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    kruskal(vertices, adjMatrix);

    return 0;
}
