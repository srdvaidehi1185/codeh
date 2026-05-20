#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* newNode(int val){

    Node* temp = new Node();

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}

int getHeight(Node* root){

    if(root == NULL){
        return 0;
    }

    return root->height;
}

int getBalance(Node* root){

    if(root == NULL){
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* y){

    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(getHeight(y->left),
                         getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                         getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x){

    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(getHeight(x->left),
                         getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                         getHeight(y->right));

    return y;
}

Node* insert(Node* root, int val){

    if(root == NULL){
        return newNode(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }

    else if(val > root->data){
        root->right = insert(root->right, val);
    }

    else{
        return root;
    }

    root->height = 1 + max(getHeight(root->left),
                            getHeight(root->right));

    int balance = getBalance(root);

    // LL Rotation
    if(balance > 1 && val < root->left->data){
        return rightRotate(root);
    }

    // RR Rotation
    if(balance < -1 && val > root->right->data){
        return leftRotate(root);
    }

    // LR Rotation
    if(balance > 1 && val > root->left->data){

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    // RL Rotation
    if(balance < -1 && val < root->right->data){

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

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

int main(){

    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++){

        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }

    cout << "\nInorder Traversal of AVL Tree: ";

    inorder(root);

    return 0;
}