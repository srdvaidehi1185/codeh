#include <iostream>
using namespace std;

#define SIZE 10

struct Client {

    string name;

    long long phone;

    bool occupied = false;
};

Client table[SIZE];

int hashFunction(long long phone) {

    return phone % SIZE;
}

void insert(string name, long long phone) {

    int index = hashFunction(phone);

    while(table[index].occupied) {

        index = (index + 1) % SIZE;
    }

    table[index].name = name;

    table[index].phone = phone;

    table[index].occupied = true;
}

void search(long long phone) {

    int index = hashFunction(phone);

    int start = index;

    while(table[index].occupied) {

        if(table[index].phone == phone) {

            cout << "\nRecord Found:\n";

            cout << "Name : "
                 << table[index].name << endl;

            cout << "Phone : "
                 << table[index].phone << endl;

            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    cout << "\nRecord Not Found!\n";
}

void display() {

    cout << "\nHash Table:\n";

    for(int i = 0; i < SIZE; i++) {

        cout << i << " : ";

        if(table[i].occupied)

            cout << table[i].name
                 << " - "
                 << table[i].phone;

        else

            cout << "Empty";

        cout << endl;
    }
}

int main() {

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