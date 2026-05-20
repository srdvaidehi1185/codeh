#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if(root == NULL){
        return newNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

void leafNode(Node* root) {
    if (root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) {
        cout << root -> data << " ";
    }
    leafNode(root->left);
    leafNode(root->right);
}

int main(){
    Node* root = NULL;

    int n, value;
    cout << "Enter the number of nodes : " ;
    cin >> n;

    for(int i = 0; i<n; i++){
        cout << "Enter value : ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "Binary Tree Created Successfully!" << endl;
    cout << "Leaf Nodes : ";
    leafNode(root);

    return 0;
}