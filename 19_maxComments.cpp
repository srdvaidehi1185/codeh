#include <iostream>
#include <vector>
using namespace std;

struct User{

    string name;

    int comments;
};

class Graph{

    int V;

    vector<User> users;

public:

    Graph(int n){

        V = n;

        users.resize(V);
    }

    void addUser(int index, string name, int comments){

        users[index] = {name, comments};
    }

    void findMaxMinComments(){

        int maxIndex = 0;

        int minIndex = 0;

        for(int i = 1; i < V; i++){

            if(users[i].comments > users[maxIndex].comments){

                maxIndex = i;
            }

            if(users[i].comments < users[minIndex].comments){

                minIndex = i;
            }
        }

        cout << "\nUser with Maximum Comments : ";

        cout << users[maxIndex].name;

        cout << " (" << users[maxIndex].comments << ")";

        cout << "\nUser with Minimum Comments : ";

        cout << users[minIndex].name;

        cout << " (" << users[minIndex].comments << ")";
    }
};

int main(){

    Graph g(4);

    g.addUser(0, "Vaidehi", 120);
    g.addUser(1, "Samruddhi", 300);
    g.addUser(2, "Avni", 50);
    g.addUser(3, "Sara", 200);

    g.findMaxMinComments();

    return 0;
}