#include <iostream>
#include <climits>
using namespace std;

#define MAX 10
#define INF 99999

int V;

void dijkstra(int graph[MAX][MAX], int src) {

    int dist[MAX];

    bool visited[MAX] = {0};

    for(int i = 0; i < V; i++) {

        dist[i] = INF;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {

        int min = INF;

        int u = -1;

        for(int i = 0; i < V; i++) {

            if(!visited[i] && dist[i] <= min) {

                min = dist[i];

                u = i;
            }
        }

        visited[u] = true;

        for(int v = 0; v < V; v++) {

            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest Distances from Source Vertex:\n";

    for(int i = 0; i < V; i++) {

        cout << "To " << i
             << " = "
             << dist[i]
             << endl;
    }
}

int main() {

    int graph[MAX][MAX];

    int src;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src);

    return 0;
}