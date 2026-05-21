#include <iostream>
#include <bits/stdc++.h>
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

Node* insert(Node* root , int val){
    Node* newnode = newNode(val);
    if(root == NULL){
        return newnode;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL){
            temp->left = newnode;
            return root;
        }
        else{
            q.push(temp -> left);
        }

        if(temp->right == NULL){
            temp->right = newnode;
            return root;
        }
        else{
            q.push(temp -> right);
        }
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
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
    cout << "Inorder Traversal : ";
    inorder(root);

    return 0;
}
