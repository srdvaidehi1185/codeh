#include <iostream>
using namespace std;

#define SIZE 10

struct Client {

    string name;

    long long phone;
};

struct Node {

    Client data;

    Node* next;
};

Node* table[SIZE];

int comparisons = 0;

int hashFunction(long long phone) {

    return phone % SIZE;
}

void insert(string name, long long phone) {

    int index = hashFunction(phone);

    Node* newNode = new Node;

    newNode->data.name = name;

    newNode->data.phone = phone;

    newNode->next = table[index];

    table[index] = newNode;
}

void search(long long phone) {

    int index = hashFunction(phone);

    Node* temp = table[index];

    comparisons = 0;

    while(temp != NULL) {

        comparisons++;

        if(temp->data.phone == phone) {

            cout << "\nRecord Found:\n";

            cout << "Name : "
                 << temp->data.name << endl;

            cout << "Phone : "
                 << temp->data.phone << endl;

            cout << "Comparisons : "
                 << comparisons << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nRecord Not Found!\n";

    cout << "Comparisons : "
         << comparisons << endl;
}

void display() {

    cout << "\nHash Table:\n";

    for(int i = 0; i < SIZE; i++) {

        cout << i << " : ";

        Node* temp = table[i];

        while(temp != NULL) {

            cout << "("
                 << temp->data.name
                 << ", "
                 << temp->data.phone
                 << ") -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

int main() {

    for(int i = 0; i < SIZE; i++) {

        table[i] = NULL;
    }

    int n;

    cout << "Enter number of clients: ";
    cin >> n;

    string name;

    long long phone;

    for(int i = 0; i < n; i++) {

        cout << "\nEnter name: ";
        cin >> name;

        cout << "Enter phone number: ";
        cin >> phone;

        insert(name, phone);
    }

    display();

    cout << "\nEnter phone number to search: ";
    cin >> phone;

    search(phone);

    return 0;
}