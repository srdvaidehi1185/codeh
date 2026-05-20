#include <iostream>
#include <stack>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool isOperator(char ch){
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

Node* constructTree(string postfix){
    stack<Node*> s;

    for(int i = 0; i<postfix.length(); i++){
        char ch = postfix[i];

        Node* temp = newNode(ch);

        if(!isOperator(ch)){
            s.push(temp);
        }
        else{
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();

            s.push(temp);
        }
    }
    return s.top();
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    string postfix;
    cout << "Enter the postfix expression : ";
    cin >> postfix;

    Node* root = constructTree(postfix);

    cout << "Inorder Traversal of Postfix is : " ;
    inorder(root);
    cout << "\nPreorder Traversal of Postfix is : " ;
    preOrder(root);
    cout << "\nPostorder Traversal of Postfix is : " ;
    postOrder(root);

    return 0;
}