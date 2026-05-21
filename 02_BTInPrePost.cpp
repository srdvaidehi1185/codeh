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
