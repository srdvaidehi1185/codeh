#include <iostream>
#include <vector>
using namespace std;

struct User{

    string name;
};

class Graph{

    int V;

    vector<User> users;

    vector<vector<int>> adj;

public:

    Graph(int n){

        V = n;

        users.resize(V);

        adj.resize(V);
    }

    void addUser(int index, string name){

        users[index] = {name};
    }

    void addFriend(int u, int v){

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    void findMaxFriends(){

        int maxFriends = 0;

        int index = 0;

        for(int i = 0; i < V; i++){

            if(adj[i].size() > maxFriends){

                maxFriends = adj[i].size();

                index = i;
            }
        }

        cout << "\nUser with Maximum Friends : ";

        cout << users[index].name;

        cout << " (" << maxFriends << " friends)";
    }
};

int main(){

    Graph g(4);

    g.addUser(0, "Vaidehi");
    g.addUser(1, "Samruddhi");
    g.addUser(2, "Avni");
    g.addUser(3, "Sara");

    g.addFriend(0, 1);
    g.addFriend(0, 2);
    g.addFriend(0, 3);
    g.addFriend(1, 2);

    g.findMaxFriends();

    return 0;
}