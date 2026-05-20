#include <iostream>
#include <algorithm>
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
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

int height(Node* root) {
    if(root == NULL){
        return 0;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return 1+max(leftheight, rightheight);

}

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if( abs(lh-rh)<=1 &&
        isBalanced(root->left) &&
        isBalanced(root->right) ) {
            return true;
        }
    else{
        return false;
    }
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

    if(isBalanced(root)){
        cout << "\nTree is Height Balanced";
    }
    else{
        cout << "\nTree is NOT Height Balanced";
    }

    return 0;
}