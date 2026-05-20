#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Vertex{
    string name;
};

class Graph{
    int V;
    vector<Vertex> vertices;
    vector<vector<int>> adj;
    vector<bool> visited;

    public:
    Graph(int n){
        V = n;
        vertices.resize(V);
        adj.resize(V);
        visited.resize(V);

    }

    void addVertex(int index, string name){
        vertices[index] = {name};
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v, bool firstCall = true){
        if(firstCall){
            visited.assign(V, false);
            cout << "DFS Traversal :";
        }
        visited[v] = true;
        cout << vertices[v].name << " ";

        for(int neighbour : adj[v]){
            if(!visited[neighbour]){
                DFS(neighbour, false);
            }
        }
        }
};

int main() {

    Graph g(4);

    g.addVertex(0, "A");
    g.addVertex(1, "B");
    g.addVertex(2, "C");
    g.addVertex(3, "D");

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.DFS(0);

    return 0;
}