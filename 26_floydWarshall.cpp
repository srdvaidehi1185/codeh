#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

int V;

void floydWarshall(int graph[MAX][MAX]) {

    int dist[MAX][MAX];

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            dist[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < V; k++) {

        for(int i = 0; i < V; i++) {

            for(int j = 0; j < V; j++) {

                if(dist[i][k] + dist[k][j]
                   < dist[i][j]) {

                    dist[i][j] =
                    dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            if(dist[i][j] == INF)
                cout << "INF ";

            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {

    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < V; j++) {

            cin >> graph[i][j];
        }
    }

    floydWarshall(graph);

    return 0;
}