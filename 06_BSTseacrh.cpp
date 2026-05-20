#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val){
    if(root == NULL){
        return newNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

Node* search(Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

int main(){
    Node* root = NULL;
    int n, value, key;

    cout << "Enter the number of node : ";
    cin >> n;

    for(int i = 0; i<n; i++){
        cout << "Enter the value : ";
        cin >> value;

        root = insert(root, value);
    }
    cout << endl;

    cout << "Enter the element to search : ";
    cin >> key;

    Node* result = search(root, key);

    if(result == NULL){
        cout << "Element not found!"<< endl;
    }
    else{
        cout << "Element found : " << result->data << endl;
    }

    return 0;
}