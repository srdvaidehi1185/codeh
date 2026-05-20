#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

int V;

void bellmanFord(int edges[][3], int E, int src) {

    int dist[MAX];

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int i = 1; i <= V - 1; i++) {

        for(int j = 0; j < E; j++) {

            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != INF &&
               dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < E; j++) {

        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != INF &&
           dist[u] + w < dist[v]) {

            cout << "\nGraph contains Negative Weight Cycle!\n";

            return;
        }
    }

    cout << "\nBellman-Ford Shortest Distances:\n";

    for(int i = 0; i < V; i++) {

        cout << "To " << i
             << " = "
             << dist[i]
             << endl;
    }
}

int main() {

    int E, src;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int edges[MAX][3];

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++) {

        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    cout << "Enter source vertex: ";
    cin >> src;

    bellmanFord(edges, E, src);

    return 0;
}