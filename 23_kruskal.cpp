#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {

    int u, v, w;
};

struct Subset {

    int parent;
};

int find(vector<Subset>& subsets, int i) {

    if(subsets[i].parent != i) {

        subsets[i].parent = find(subsets,
                                 subsets[i].parent);
    }

    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {

    subsets[find(subsets, y)].parent =
    find(subsets, x);
}

void kruskalMST() {

    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    sort(edges.begin(), edges.end(),

         [](Edge a, Edge b) {

            return a.w < b.w;
         });

    vector<Subset> subsets(V + 1);

    for(int i = 1; i <= V; i++) {

        subsets[i].parent = i;
    }

    int mstWeight = 0;

    int count = 0;

    cout << "\nSelected Edges in MST:\n";

    for(int i = 0;
        i < E && count < V - 1;
        i++) {

        if(find(subsets, edges[i].u)
           !=
           find(subsets, edges[i].v)) {

            cout << edges[i].u
                 << " -- "
                 << edges[i].v
                 << " == "
                 << edges[i].w
                 << endl;

            mstWeight += edges[i].w;

            Union(subsets,
                  edges[i].u,
                  edges[i].v);

            count++;
        }
    }

    cout << "\nMinimum Cost = "
         << mstWeight << endl;
}

int main() {

    kruskalMST();

    return 0;
}