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
    root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);

}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";

}

int main(){
    Node* root = NULL;
    int n , value;

    cout << "Enter the number of nodes : " ;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cout << "Enter the value : ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "BT created successfully!" << endl;

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal : ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    postorder(root);
    cout << endl;

    return 0;

}