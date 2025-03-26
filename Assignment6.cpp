#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<vector<int>> adjMat;
vector<bool> visited;

void dfs(int node,vector<int> &component,int &n){
    visited[node] = true;
    component.push_back(node);

    for(int i=0 ; i<n ; i++){
        if(!visited[i] && adjMat[node][i]==1){
            dfs(i,component,n);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m; // input the number of vertices and no of edges

    adjMat.resize(n,vector<int>(n,0));
    visited.resize(n,false);

    // Read edges
    for(int i=0 ; i < m ; i++){
        int a,b; 
        cin>>a>>b;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }

    vector<vector<int>> components;

    for(int i=0 ; i < n ; i++){ // for loop to take care if there are multiple connected components
        if(!visited[i]){
            vector<int> component;
            dfs(i,component,n);
            components.push_back(component);
        }
    }

    if(components.size() == 1){
        cout<<"Graph is fully connected and has only 1 Connected Component."<<endl;
    }else{
        cout<<"Graph is Not connected and has "<<components.size()<<" Componets"<<endl;
        cout<<"Connected Components are:"<<endl;
        for(int i=0 ; i<components.size() ; i++){
            cout<<"Component "<<i+1<<" : ";
            for(auto &node: components[i]){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
}